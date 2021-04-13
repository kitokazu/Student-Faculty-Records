#include <iostream>
#include "Registrar.h"

using namespace std;

//Default Constructor
Registrar::Registrar()
{
    m_time = 0;
    m_numOfWindows = 0;
    m_windows = new Window[0];
    m_students = new Student[0];
    //GenQueue<Student> waitingQueue = new GenQueue<Student>();

}
Registrar::Registrar(int numOfWindows, int numOfStudentsArriving)
{
    m_time = 0;
    m_numOfWindows = numOfWindows;
    m_windows = new Window[numOfWindows];
     m_students = new Student[numOfStudentsArriving];
}
//Deconstructor
Registrar::~Registrar()
{
    delete[] m_windows;
    delete[] m_students;
}
//Getters
//Setters
//void Registrar::setWindows(Window *windows)
//{
//
//}
void Registrar::setStudents()
{

}
//Method
//Runs the simulation of the students arriving at the registrar
void Registrar::RunSimulation()//
{
    
    //Run until the windows are empty no people in queue
    /*while(!windowAreEmpty() || !queue.isEmpty())
    {
        //Add students that are arriving to the queue
        if()
        queue.enqueue(student[0])

        //If a window is open put that student there
        //Call the decrement method on every window

        //If the return is not null then the student is done 
        //meaning it will be added to the students array to be used for stats
        //After adding the student set that windows student to null



        //Loop through Queue and add one to every student in the queue
    }*/
    

}
void Registrar::calculateStatistics()
{

}
bool Registrar::windowsAreEmpty()
{
    for (int i = 0; i < m_numOfWindows; i++)
    {
        if(m_windows[i].isUsed())
        {
            return false;
        }
    }
    return true;
    
}