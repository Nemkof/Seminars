#include <iostream>
using namespace std;

int main() {
    // структуру преобразовать в массив char и обратно преобразовать в структуру.
    // вывести на консоль промежуточные результаты

    int* I = new int[10];
    for(int i = 0; i < 10; i++) {
        I[i] = 60 + i;
    }
    for(int i = 0; i < 10; i++) {
        cout << I[i] << ' ';
    }
    cout << endl;
    char* C = new char[10];
    C = reinterpret_cast<char*>(I);
    for(auto : C) {
        cout << it << ' ';
    }
    cout << endl;

    delete[] I;
    delete[] C;
    return 0;
}
