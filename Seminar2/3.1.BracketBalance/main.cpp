// На вход дают вектор, содержащий скобочки (){}[]
// На выходе надо получить либо success, если баланс скобок соблюдается
// Либо Индекс первой скобочки, которая нарушает баланс
#include <fstream>
#include <iostream>
#include <stack>

using namespace std;

int check_bracket_balance(istream& s) {
    string inputLine;
    getline(s, inputLine);

    stack<char> Braces;

    for (int i = 0; i < inputLine.length(); i++) {
        char helper = inputLine[i];

        if (helper == '[' || helper == '{' || helper == '(') {
            Braces.push(helper);
        } else if (helper == ']' || helper == '}' || helper == ')') {
            if (Braces.empty()) {
                return i + 1; // Возвращаем индекс закрывающей скобки
            }

            char top = Braces.top();
            if ((helper == ']' && top != '[') ||
                (helper == '}' && top != '{') ||
                (helper == ')' && top != '(') ) {
                return i + 1; // Возвращаем индекс закрывающей скобки
            }

            Braces.pop();
        }
    }

    if (!Braces.empty()) {
        return inputLine.length(); // Возвращаем индекс первой незакрытой скобки
    }

    return -2; // Успех
}

int main() {
    std::ifstream inputFile("../input.txt");

    if (!inputFile.is_open()) {
        cerr << "File isn't open!" << endl;
        return 1;
    }

    int ans = check_bracket_balance(inputFile);

    if(ans == -2) cout << "Success" << endl;
    else cout << ans << endl;

    inputFile.close();
    return 0;
}

