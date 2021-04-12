#include <iostream>
#include "Window.h"
#ifndef WINDOW_H
#define WINDOW_H


using namespace std;

class Registrar
{
    public:
        //Default Constructor
        Registrar(int numOfWindows, Student *students); 
        //Deconstructor
        ~Registrar();
        //Getters
        //Setters
        void setWindows(Window *windows);
        void setStudents();
        //Methods
        void runIteration();
        void CalculateStatistics(); 


    private:
        //Array of windows that is the number if windows
        Window *m_windows;
        //Array of all the students that will arrive to the Registrar
        Student *m_students;
        int time;

        
        
};
#endif