// Входные данные - строка-предложение, в котором каждое слово является анаграммой
// + файл-словарь, по которому нужно расшифровывать слова
// Выходные данные - расшифрованное предложение
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

// Функция для сортировки символов в слове
string sortString(const string& str) {
    string sortedStr = str;
    sort(sortedStr.begin(), sortedStr.end());
    return sortedStr;
}

// Функция для загрузки словаря из файла
map<string, string> loadDictionary(const string& filename) {
    map<string, string> dictionary;
    ifstream file(filename);
    string word;

    while (getline(file,word)) {
        dictionary.at(word)=sortString(word);
    }
    return std::move(dictionary);
}

// Функция для расшифровки анаграмм
vector<string> decryptAnagrams(const map<string, string>& dictionary) {
    string inputString;

    cout << "Enter your anagrams: ";
    getline(cin, inputString);

    // words хранит слова нашего предложения
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
            if(dictWord.second == sortedWord) {
                result.push_back(dictWord.second);
                break; // Найдена анаграмма, выходим из перебора словаря
            }
        }
    }
    return result;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);


    const string filename = "../input.txt"; // Имя файла со словарем

    const map<string, string> dictionary = loadDictionary(filename);

    vector<string> decryptedWords = decryptAnagrams(dictionary);
    // Вывод результата
    for (const auto& word : decryptedWords) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
