#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class SumFunctor {
public:
    int evenSum = 0;
    int oddSum = 0;

    void operator()(int number) {
        if (number % 2 == 0) {
            evenSum += number;
        } else {
            oddSum += number;
        }
    }
};

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    SumFunctor sumFunctor;


    for_each(numbers.begin(), numbers.end(), sumFunctor);

    cout << "Sum even: " << sumFunctor.evenSum << endl;
    cout << "Sum uneven: " << sumFunctor.oddSum << endl;

    return 0;
}
