#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>

void toLowerCase(std::string& str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
}

bool isAlpha(const std::string& word) {
    return std::all_of(word.begin(), word.end(), ::isalpha);
}

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error opening input file!" << std::endl;
        return 1;
    }

    std::map<std::string, int> wordCount;
    std::string word;

    while (inputFile >> word) {
        toLowerCase(word);
        if (isAlpha(word)) {
            wordCount[word]++;
        }
    }

    inputFile.close();

    outputFile << "Word Frequency:\n";
    for (const auto& pair : wordCount) {
        outputFile << pair.first << ": " << pair.second << "\n";
    }

    std::string mostFrequentWord;
    int maxCount = 0;
    for (const auto& pair : wordCount) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            mostFrequentWord = pair.first;
        }
    }

    outputFile << "\nMost frequent word: " << mostFrequentWord << " (" << maxCount << " occurrences)\n";

    std::cout << "The frequency dictionary has been written to output.txt" << std::endl;
    return 0;
}
