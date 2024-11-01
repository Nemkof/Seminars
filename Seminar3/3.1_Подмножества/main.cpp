/// Определить, является ли множество подмножеством другого множества
#include <iostream>
#include <vector>
using namespace std;

template <class T>
bool foo(vector<T>& first, vector<T>& second)
{
    if(first.size() < second.size()) return false;
    size_t i = 0, j = 0;
    while(i < first.size() && j < second.size())
    {
        if(second.at(j) == first.at(i))
        {
            j++;
        }
        i++;
    }
    if(j != second.size()) return false;
    return true;
}


int main() {
    vector<int> int_first = {1,2,3,4,5,6,7,8,9};
    vector<int> int_second = {1,3,5,7,8};
    vector<int> int_third = {2,1,3,5,7,8};

    cout << foo(int_first, int_second) << endl;
    cout << foo(int_first, int_third) << endl;
    cout << foo(int_second, int_first) << endl;

    vector<string> string_first = {"aaa", "bbb", "ccc", "ddd", "eee", "fff"};
    vector<string> string_second = {"aaa", "ccc", "ddd", "eee"};
    vector<string> string_third = {"aaa", "ddd", "ccc"};

    cout << foo(string_first, string_second) << endl;
    cout << foo(string_first, string_third) << endl;
    cout << foo(string_third, string_first) << endl;

    return 0;
}