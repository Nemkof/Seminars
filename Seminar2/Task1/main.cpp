// На вход дают вектор, содержащий скобочки (){}[]
// На выходе надо получить либо success, если баланс скобок соблюдается
// Либо Индекс первой скобочки, которая нарушает баланс
#include <fstream>
#include <iostream>
#include <stack>

using namespace std;
int check_bracket_balance(ifstream& s)
{
    string inputLine;
    getline(s, inputLine);

    stack<char> Braces;

    for (size_t i = 0; i < inputLine.length(); i++) {
        char helper = inputLine[i];

        // Проверяем квадратные скобки
        if (helper == '[') {
            Braces.push('[');
        }
        else if (helper == ']') {
            if (Braces.empty()) {
                return i + 1;
            }
            if (Braces.top() != '[') {
                return i + 1;
            }

            Braces.pop();
        }

        // Проверяем фигурные скобки
        if (helper == '{') {
            Braces.push('{');
        }
        else if (helper == '}') {
            if (Braces.empty()) {
                return i + 1;
            }
            if (Braces.top() != '}') {
                return i + 1;
            }

            Braces.pop();
        }

        // Проверяем обычные скобки
        if (helper == '(') {
            Braces.push('(');
        }
        else if (helper == ')') {
            if (Braces.empty()) {
                return i + 1;
            }
            if (Braces.top() != '(') {
                return i + 1;
            }

            Braces.pop();
        }
    }
    if (Braces.empty()) {
        return -2;
    }
    else {
        return 0;
    }
    return -1;
}

int main() {
    ifstream our_stream("input.txt");

    int ans = check_bracket_balance(our_stream);

    if(ans == -2) cout << "Success" << endl;
    else cout << ans << endl;

    return 0;
}

