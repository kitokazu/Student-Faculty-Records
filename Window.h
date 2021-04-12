#include <iostream>
#include "Student.h"
#ifndef WINDOW_H
#define WINDOW_H


using namespace std;

class Window
{
    public:
        //Default Constructor
        Window(); 
        //Deconstructor
        ~Window();
        //Getters
        Student* getStudent();
        int getIdleTime();
        //Setters
        void setStudent(Student *student);
        void setIdleTime(int time);
        //Methods
        //Checks if the window is being used or not
        bool isUsed();
        //Decrements the time left on the student at this window
        void Decrement();
        //If time is 0 student = null else remove one tick from student 


    private:
        //Student object that holds the student currently at the window
        Student *m_student;
        //Integer that holds the amount of time that the window has been idle
        int m_idleTime;
        
        
};
#endif