// Реализовать шаблонный класс ForwardList используя умные указатели
// Класс должен содержать функции:
// pushFront(const& T)
// popFront()
// bool empty()
// const T& front() const

#include <iostream>
#include "ForwardList.h"
#include <windows.h>
int main() {
    SetConsoleOutputCP(CP_UTF8);


    ForwardList<int> list;
    string is_empty = list.empty() ? "тут пусто" : "тут не пусто";
    cout << is_empty << endl;

    list.push_front(5);
    list.push_front(3);
    list.push_front(1);

    is_empty = list.empty() ? "тут пусто" : "тут не пусто";
    cout << is_empty << endl;


    std::cout << std::endl;
    std::cout << "Список: ";
    while (!list.empty()) {
        std::cout << list.front() << " ";
        list.pop_front();
    }
    std::cout << std::endl;


    is_empty = list.empty() ? "ут пусто" : "тут не пусто";
    cout << is_empty << endl;

    return 0;
}
