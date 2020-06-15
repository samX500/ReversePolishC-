//
// Created by Proprio on 2020-05-24.
//
#include <iostream>

#ifndef STACK_LIST_HPP
#define STACK_LIST_HPP

#include <stdexcept>

template<typename T>
class List {
    struct Node {
        Node *previous;
        Node *next;
        T data;
    };

    Node *head;
    Node *tail;
    int size;

public:
    List() {
        instantiateList();
    }

private:
    void instantiateList() {
        head = new Node();
        tail = new Node();

        head->next = tail;
        head->previous = nullptr;

        tail->next = nullptr;
        tail->previous = head;

        size = 0;
    }

public:
    int getSize() {
        return size;
    }

public:
    bool isEmpty() {
        return head->next == tail;
    }

public:
    void add(T item) {
        Node *newItem = new Node();

        newItem->next = tail;
        newItem->previous = tail->previous;
        tail->previous->next = newItem;
        tail->previous = newItem;

        newItem->data = item;

        size++;
    }


private:
    T getPositiveIndex(int index) {
        int currentIndex = 0;
        Node *currentNode = head->next;
        while (currentNode->next != nullptr) {
            if (currentIndex == index) {
                T item = currentNode->data;
                return item;
            } else {
                currentNode = currentNode->next;
                currentIndex++;
            }
        }
        std::string sizeAsString = std::to_string(getSize());
        std::string indexAsString = std::to_string(index);
        throw std::invalid_argument(
                "index input out of bound\tSize:" + sizeAsString + "\tIndex: " + indexAsString + "\n");
    }

private:
    T getNegativeIndex(int index) {
        int currentIndex = -1;
        Node *currentNode = tail->previous;
        while (currentNode->previous != nullptr) {
            if (currentIndex == index) {
                T item = currentNode->data;
                return item;
            } else {
                currentNode = currentNode->previous;
                currentIndex--;
            }
        }
        std::string sizeAsString = std::to_string(getSize());
        std::string indexAsString = std::to_string(index);
        throw std::invalid_argument(
                "index input out of bound\tSize:" + sizeAsString + "\tIndex: " + indexAsString + "\n");
    }


public:
    T get(int index) {
        if (isEmpty())
            throw std::invalid_argument("cannot get item from empty list");
        else if (index >= 0)
            return getPositiveIndex(index);
        else
            return getNegativeIndex(index);
    }


private:
    void removeNode(Node *currentNode) {
        currentNode->previous->next = currentNode->next;
        currentNode->next->previous = currentNode->previous;

        delete (currentNode);
        size--;
    }

private:
    T removePositiveIndex(int index) {
        int currentIndex = 0;
        Node *currentNode = head->next;
        while (currentNode->next != nullptr) {
            if (currentIndex == index) {
                T item = currentNode->data;
                removeNode(currentNode);
                return item;
            } else {
                currentNode = currentNode->next;
                currentIndex++;
            }
        }
        std::string sizeAsString = std::to_string(getSize());
        std::string indexAsString = std::to_string(index);
        throw std::invalid_argument(
                "index input out of bound\tSize:" + sizeAsString + "\tIndex: " + indexAsString + "\n");
    }

private:
    T removeNegativeIndex(int index) {
        int currentIndex = -1;
        Node *currentNode = tail->previous;
        while (currentNode->previous != nullptr) {
            if (currentIndex == index) {
                T item = currentNode->data;
                removeNode(currentNode);
                return item;
            } else {
                currentNode = currentNode->previous;
                currentIndex--;
            }
        }
        std::string sizeAsString = std::to_string(getSize());
        std::string indexAsString = std::to_string(index);
        throw std::invalid_argument(
                "index input out of bound\tSize:" + sizeAsString + "\tIndex: " + indexAsString + "\n");
    }

public:
    T remove(int index) {
        if (isEmpty())
            throw std::invalid_argument("cannot remove item from empty list");
        else if (index >= 0)
            return removePositiveIndex(index);
        else
            return removeNegativeIndex(index);
    }

public:
    bool contains(T item){
        Node* currentNode = head->next;
        while(currentNode->next != nullptr)
        {
            if(currentNode->data == item)
                return true;
            else
                currentNode = currentNode->next;
        }

        return false;
    }
};


#endif //STACK_LIST_HPP
