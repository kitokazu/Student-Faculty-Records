#include <iostream>
#include "Window.h"
#include "GenQueue.h"
#ifndef REGISTRAR_H
#define REGISTRAR_H


using namespace std;

class Registrar
{
    public:
        //Default Constructor
        Registrar();
        //Overloaded Constructor
        Registrar(int numOfWindows, int numOfStudentsArriving); 
        //Deconstructor
        ~Registrar();
        //Getters
        //Setters
        void setWindows(Window *windows);
        void setStudents();
        //Methods
        void RunSimulation();
        void calculateStatistics(); 
        bool windowsAreEmpty();


    private:
        //Array of windows that is the number if windows
        Window *m_windows;
        //Array of all the students that will arrive to the Registrar
        Student *m_students;
        //Variable that stores the total number of windows
        int m_numOfWindows;
        //Variable that stores the current time in ticks
        int m_time;
        GenQueue<Student> waitingQueue;
 
        
};
#endif