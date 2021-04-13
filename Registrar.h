#include <iostream>
#include "Window.h"
#include "GenQueue.h"
#include <vector>
#ifndef REGISTRAR_H
#define REGISTRAR_H



using namespace std;

class Registrar
{
    public:
        //Default Constructor
        Registrar();
        //Overloaded Constructor
        Registrar(int numOfWindows); 
        //Deconstructor
        ~Registrar();
        //Getters
        //Setters
        void setWindows(Window *windows);
        void setStudents();
        //Methods
        void RunSimulation(vector<Student> students);
        void calculateStatistics(); 
        bool windowsAreEmpty();


    private:
        //Vector of windows that is the number if windows
        vector<Window> m_windows;
        //Vectpr of all the students that will arrive to the Registrar
        vector<Student> m_students;
        //Variable that stores the current time in ticks
        int m_time;
        GenQueue<Student> *m_waitingQueue;
 
        
};
#endif