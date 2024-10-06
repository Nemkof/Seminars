/// Удалить элемент из вектора следующим образом:
/// свапнуть его с последним и изменить размер на 1
#include <iostream>
#include "MyVector.h"
int main() {
    Vector<int> myVector(5);
    myVector.pushBack(1);
    myVector.pushBack(2);
    myVector.pushBack(3);
    myVector.pushBack(4);
    myVector.pushBack(5);

    std::cout << "Vector before erase: ";
    for (int i = 0; i < myVector.getSize(); i++) {
        std::cout << myVector[i] << " ";
    }
    std::cout << std::endl;

    myVector.erase(2); // Удаляем элемент с индексом 2

    std::cout << "Vector after erase: ";
    for (int i = 0; i < myVector.getSize(); i++) {
        std::cout << myVector[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
