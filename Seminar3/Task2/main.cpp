// Входные данные - строка-предложение, в котором каждое слово является анаграммой
// + файл-словарь, по которому нужно расшифровывать слова
// Выходные данные - расшифрованное предложение
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
using namespace std;

// Функция для сортировки символов в слове
string sortString(const string& str) {
    string sortedStr = str;
    sort(sortedStr.begin(), sortedStr.end());
    return sortedStr;
}

// Функция для загрузки словаря из файла
vector<string> loadDictionary(const string& filename) {
    vector<string> dictionary;
    ifstream file(filename);
    string word;

    while (getline(file,word)) {
        dictionary.push_back(word);
    }
    return dictionary;
}

// Функция для расшифровки анаграмм
vector<string> decryptAnagrams(const vector<string>& dictionary) {
    string inputString;

    cout << "Введите строку: ";
    getline(cin, inputString);

    vector<string> words;

    stringstream ss(inputString);
    string word;
    while (ss >> word) {
        words.push_back(word);
    }

    vector<string> result;
    for(auto it: words) {
        string sortedWord = sortString(it);
        for (const auto& dictWord : dictionary) {
            if (sortString(dictWord) == sortedWord) {
                result.push_back(dictWord);
                break; // Найдено соответствие, выходим из цикла
            }
        }
    }
    return result;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);


    const string filename = "input.txt"; // Имя файла со словарем

    const vector<string> dictionary = loadDictionary(filename);

    vector<string> decryptedWords = decryptAnagrams(dictionary);
    // Вывод результата
    for (const auto& word : decryptedWords) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

std::vector<std::string> splitString(const std::string& str) {
    std::vector<std::string> words;
    std::stringstream ss(str);
    std::string word;

    while (ss >> word) {
        words.push_back(word);
    }

    return words;
}

