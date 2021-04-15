//Name: Luke Driscoll, Kai Itokazu
//Student ID Number: 2344496, 2344742
//Student Email: ldriscoll@chapman.edu, itokazu@chapman.edu
//Class: CPSC-350-01 - Prof. German
//Assignment 5: Registrars Office
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
        virtual T remove(T key) = 0;
        virtual int find(T value) = 0;
        virtual bool isEmpty() = 0;
        virtual int getSize() = 0;
        //virtual void printList(bool printLink) = 0;
};


#endif