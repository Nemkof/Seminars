/// Удалить элемент из вектора следующим образом:
/// свапнуть его с последним и изменить размер на 1
#include <iostream>
#include <vector>

using namespace std;
int main() {
    vector<int> myVector = {1,2,3,4,5,6,7,8,9,10};

    std::cout << "Vector before erase: ";
    for (int i = 0; i < myVector.size(); i++) {
        std::cout << myVector[i] << " ";
    }
    std::cout << std::endl;

    int helper = myVector.at(myVector.size() - 1);
    myVector.at(3) = helper;
    myVector.pop_back();

    std::cout << "Vector after erase: ";
    for (int i = 0; i < myVector.size(); i++) {
        std::cout << myVector[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}