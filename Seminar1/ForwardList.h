#ifndef FORWARDLIST_H
#define FORWARDLIST_H
#include<iostream>
#include<memory>

template<typename T>
class ForwardList{
private:
    struct Node{
        T data;
        std::unique_ptr<Node> next;
        Node(const T& _data){
            data = _data;
        }
        ~Node(){}
    };
    std::unique_ptr<Node> head;
public:
    ForwardList(){
        head = nullptr;
    }
    ~ForwardList(){}

    void push_front(const T& data){
        std::unique_ptr<Node> node = std::make_unique<Node>(data);
        node->next = std::move(head);
        head = std::move(node);

    }
    void pop_front(){
        if(head){
            head = std::move(head->next);
        }
    }

    bool empty() const{
        return !head;
    }

    T& front() const
    {
        return head->data;
    }

};

#endif