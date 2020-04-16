
#ifndef FORWARD_LIST_NOREPO_NODE_H
#define FORWARD_LIST_NOREPO_NODE_H

#include <iostream>

template <typename T>
class Node{
public:
    T value;
    Node<T>* next;
public:
    Node(T value , Node<T>* next){
        this->value = value;
        this->next = next;
    }
    ~Node(){
        next = nullptr;
    }
};



#endif //FORWARD_LIST_NOREPO_NODE_H
