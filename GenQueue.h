#ifndef GENQUEUE_H
#define GENQUEUE_H
#include <iostream>
#include "List.h"
#include "LinkedList.h"

using namespace std;

template <typename T>
class GenQueue {
    public:
        GenQueue();
        GenQueue(int maxSize);
        ~GenQueue();
        DoublyLinkedList<T> *linkedlist = new DoublyLinkedList<T>();
        //core functions
        void insert(T d); //aka enqueue
        T remove(); //aka dequeue

        //aux functions
        //void printArray();
        void enqueue(T data);
        T peek();
        bool isFull();
        bool isEmpty();
        int getSize();
    private:
        int head;
        int rear;
        int mSize;
        int numElements;
        T *myQueue;
        T *myChar;    
};

template <typename T>
GenQueue<T>::GenQueue(){
}

template <typename T>
GenQueue<T>::GenQueue(int d){
}

template <typename T>
GenQueue<T>::~GenQueue(){
    delete linkedlist;
}

template <typename T>
void GenQueue<T>::insert(T d){
    linkedlist->insertBack(d);
}

template <typename T>
T GenQueue<T>::remove(){
    return linkedlist->removeFront();
}

template <typename T>
bool GenQueue<T>::isEmpty() {
    return linkedlist->isEmpty();
}

template <typename T>
int GenQueue<T>::getSize() {
    return linkedlist->getSize();
}



#endif