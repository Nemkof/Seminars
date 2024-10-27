#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
void squareNumbers(vector<int>& numbers, function<int>& f) {
    transform(numbers.begin(), numbers.end(), numbers.begin(), f);
}

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5};

    cout << "Our numbers: ";
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << endl;

    squareNumbers(numbers, (function<int> &) [](int n) { return n * n; });

    cout << "Our numbers in square: ";
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
