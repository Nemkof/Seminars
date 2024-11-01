// �室�� ����� - ��ப�-�।�������, � ���஬ ������ ᫮�� ���� ����ࠬ���
// + 䠩�-᫮����, �� ���஬� �㦭� ����஢뢠�� ᫮��
// ��室�� ����� - ����஢����� �।�������
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

// �㭪�� ��� ���஢�� ᨬ����� � ᫮��
string sortString(const string& str) {
    string sortedStr = str;
    sort(sortedStr.begin(), sortedStr.end());
    return sortedStr;
}

// �㭪�� ��� ����㧪� ᫮���� �� 䠩��
map<string, string> loadDictionary(const string& filename) {
    map<string, string> dictionary;
    ifstream file(filename);
    string word;

    while (getline(file,word)) {
        dictionary.at(word)=sortString(word);
    }
    return std::move(dictionary);
}

// �㭪�� ��� ����஢�� ����ࠬ�
vector<string> decryptAnagrams(const map<string, string>& dictionary) {
    string inputString;

    cout << "Enter your anagrams: ";
    getline(cin, inputString);

    // words �࠭�� ᫮�� ��襣� �।�������
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
                break; // ������� ����ࠬ��, ��室�� �� ��ॡ�� ᫮����
            }
        }
    }
    return result;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);


    const string filename = "../input.txt"; // ��� 䠩�� � ᫮��६

    const map<string, string> dictionary = loadDictionary(filename);

    vector<string> decryptedWords = decryptAnagrams(dictionary);
    // �뢮� १����
    for (const auto& word : decryptedWords) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
