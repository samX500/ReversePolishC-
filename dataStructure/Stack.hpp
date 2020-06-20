//
// Created by Proprio on 2020-05-19.
//
#ifndef UNTITLED_STACK_HPP
#define UNTITLED_STACK_HPP
#include <stdexcept>

template<typename T>
class Stack {
    struct Node {
        T data;
        Node* previous;
    };


    Node* top;
    int size;

public:
    Stack() {
        top = nullptr;
        size = 0;
    }

public:
    void put(T item)
    {
        Node* newNode = new Node();
        newNode->data = item;
        newNode->previous = top;
        top = newNode;
        size++;
    }

    T pop()
    {
        if(!top)
            throw std::invalid_argument("Stack empty");

        T currentItem = top->data;
        Node* previousTop = top;
        top = top->previous;
        delete previousTop;
        size--;

        return currentItem;
    }

    int getSize() {
        return size;
    }

    void clear() {
        while(top != nullptr)
            pop();
    }
};


#endif //UNTITLED_STACK_HPP
