// Реализовать шаблонный класс ForwardList используя умные указатели
// Класс должен содержать функции:
// pushFront(const& T)
// popFront()
// bool empty()
// const T& front() const
#include <iostream>
#include "ForwardList.h"

int main() {
    ForwardList<int> list;
    string is_empty = list.empty() ? "empty" : "not empty";
    cout << is_empty << endl;

    list.push_front(5);
    list.push_front(3);
    list.push_front(1);

    is_empty = list.empty() ? "empty" : "not empty";
    cout << is_empty << endl;


    std::cout << std::endl;
    std::cout << "List: ";
    while (!list.empty()) {
        std::cout << list.front() << " ";
        list.pop_front();
    }
    std::cout << std::endl;


    is_empty = list.empty() ? "empty" : "not empty";
    cout << is_empty << endl;

    return 0;
}