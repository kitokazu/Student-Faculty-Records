#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
//#include "LinkedList.h"
using namespace std;

template <typename T>
class List{
    public:
    //Must implement every function in abstract class
        virtual void insertFront(T data) = 0;
        virtual void insertBack(T data) = 0;
        virtual void clearList() = 0;
        virtual T removeFront() = 0;
        virtual T removeBack() = 0;
        virtual T remove(int key) = 0;
        virtual int find(int value) = 0;
        virtual bool isEmpty() = 0;
        virtual size_t getSize() = 0;
        //virtual void printList(bool printLink) = 0;
};


#endif