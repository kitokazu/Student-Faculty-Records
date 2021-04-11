#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
using namespace std;

template <typename T>
class ListNode{
    public:
        ListNode();
        ListNode(T d);
        ~ListNode();
        ListNode *next;
        ListNode *prev;
        T data;
};

template <typename T>
ListNode<T>::ListNode() {}

template <typename T>
ListNode<T>::ListNode(T d){
    data = d;
    next = NULL; //might have to do nullptr or 0
    prev = NULL;

}

template <typename T>
ListNode<T>::~ListNode() {
    next = nullptr;
    prev = nullptr;
    //More code that needs to go here
}


//DoublyLinkedList Template Class
template <typename T>
class DoublyLinkedList {
    private:
        ListNode<T> *front;
        ListNode<T> *back;
        size_t listSize;
    public:
        DoublyLinkedList();
        ~DoublyLinkedList();
        void insertFront(T data);
        void insertBack(T data);
        void clearList();
        T removeFront();
        T removeBack();
        T remove(int key);
        int find(int value);
        bool isEmpty();
        size_t getSize();
        void printList(bool printLink);
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
    listSize = 0;
    front = 0;
    back = 0;
};

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    //Lets build some character
    //what do we do here
}

template <typename T>
bool DoublyLinkedList<T>::isEmpty(){
    //Checks if the front and back are pointing to null
    if ((front == 0) && (back == 0)) {
        return true;
    }
    return false;
}

template <typename T>
T DoublyLinkedList<T>::remove(int key) 
{
    ListNode<T> *current = front;
    while(current->data != key)
    {
        current = current->next;
        if(current == 0)
        {
            return 0; //done no need to proceed
        }
    }
    
    //found it, now let's proceed to remove it
    if(current == front)
    {
        front = current->next;
        front->prev = 0;
    }
    else if(current == back)
    {
        back = current->prev;
        back->next = 0;
    }
    else
    {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }

    current->next = 0;
    current->prev = 0;
    T temp = current->data;
    listSize--;
    delete current;
    return temp;
}

template <typename T>
int DoublyLinkedList<T>::find(int value) {
    int i = -1;
    ListNode<T> *current = front;
    while(current != 0) {
        ++i;
        if(current->data == value) {
            break;
        }
        else {
            current = current->next;
        }
    }
    if(current == 0) {
        //Does not exist in list
        i = -1;
    }
    return i;
}

template <typename T>
void DoublyLinkedList<T>::printList(bool printLink)
{
    ListNode<T> *current = front;
    while(current != 0){
       if(current == front){
         cout << "{FRONT}: ";
       }
       else if(current == back){
         cout << "{REAR}: ";
       }
       if(printLink)
        cout << "[ PREV: "<< current->prev << "  " << current->data << "  NEXT: "<< current->next << " ] ";
      else
        cout << "[ " << current->data << " ] ";

       current = current->next;
       if(current != 0){
         cout << " ==> ";
       }
    }
    cout << endl;
}

template <typename T>
T DoublyLinkedList<T>::removeFront() {
    ListNode<T> *tp = front;

    //check if empty
    //throw exception
    if ((front == 0) && (back == 0)) {
        cout << "ERROR" << endl;
        return 0;
    }

    if(front->next == 0){
        back = 0;
    } else {
        front->next->prev = 0;
    }
    front = front->next;
    tp->next = 0;
    T temp = tp->data;
    listSize--;
    delete tp;
    return temp;
}

template <typename T>
T DoublyLinkedList<T>::removeBack() {
    ListNode<T> *tp = back;

    //check if empty
    //throw exception

    //setting it to 0 equals null

    if(back->prev == 0) {
        front = 0;
    }
    else {
        back->prev->next = 0;
    }
    back = back->prev;
    tp->prev = 0;
    T temp = tp->data;
    listSize--;
    delete tp;
    return temp;
}

template <typename T>
void DoublyLinkedList<T>::insertFront(T data) {
    ListNode<T> *node = new ListNode<T>(data);
    //Sets the data of the node through overloaded contstructor

    if (listSize == 0) {
        //list is empty
        back = node;
    }
    else {
        //not an empty list
        front->prev = node;
        node->next = front;
    }
    front = node;
    listSize++;
}

template <typename T>
void DoublyLinkedList<T>::insertBack(T data) {
    ListNode<T> *node = new ListNode<T>(data);
    if(listSize == 0) {
        //list is empty
        front = node;
    }
    else {
        //not an empty list
        back->next = node;
        node->prev = back;
    }
    back = node;
    listSize++;
}

#endif