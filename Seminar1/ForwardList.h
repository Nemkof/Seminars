#ifndef FORWARDLIST_H
#define FORWARDLIST_H

#include <memory>
#include <stdexcept>
using namespace std;

template<typename T> class ForwardList
{
private:

    struct Node{
        T data;
        unique_ptr<Node> next;
        Node(const T& data) : data(data), next(nullptr) {
            cout << "Constructor Node" << endl;
        }
        ~Node(){ cout << "Destructor Node" << endl;}
    };

    unique_ptr<Node> head;

public:
    ForwardList() : head(nullptr) {
        cout << "Constructor List" << endl;

    }
    ~ForwardList() { cout << "Destructor List " << endl;}
    // Добавление в начало
    void push_front(const T& data)
    {
        unique_ptr<Node> node = std::make_unique<Node>(data);
        node->next = head;
        head = node;
    }

    // Удаление первого элемента
    void pop_front()
    {
        if (head) {
            head = head->next;
        }
    }

    // Проверка на пустоту
    bool empty() const
    {
        return !head;
    }

    // Получение первого элемента
    T& front() const
    {
        if(head != nullptr) return head->data;
    }
};
#endif