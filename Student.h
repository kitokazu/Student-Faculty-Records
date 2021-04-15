//Name: Luke Driscoll, Kai Itokazu
//Student ID Number: 2344496, 2344742
//Student Email: ldriscoll@chapman.edu, itokazu@chapman.edu
//Class: CPSC-350-01 - Prof. German
//Assignment 5: Registrars Office
#include <iostream>
#ifndef STUDENT_H
#define STUDENT_H


using namespace std;

class Student
{
    public:
        //Default Constructor
        Student(); 
        //Overloading Constructor
        Student(int timeAtWindow, int timeArriving); 
        //Deconstructor
        ~Student();
        //Getters
        int getTimeLeft();
        int getTotalTime();
        int getTimeArriving();
        int getTimeWaiting();
        //Setters
        void setTimeLeft(int time);
        void setTotalTime(int time);
        void setTimeArriving(int time);
        void setTimeWaiting(int time);
        //Methods
        bool operator == (Student s);
        bool operator != (Student s);
    private:
        //Integer that holds the total time standing at the window
        int m_totalTime;
        //Integer that holds the time left at the window
        int m_timeLeft;
        //Integer that holds the time arriving at the Registrars office
        int m_timeArriving;
        //Integer that holds the time waiting to get in line
        int m_timeWaiting;

        
};
#endif