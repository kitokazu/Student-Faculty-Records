#include <iostream>
#include "Registrar.h"
#include <vector>

#include <unistd.h>

using namespace std;

//Default Constructor
Registrar::Registrar()
{
    m_time = 0;
    m_waitingQueue = new GenQueue<Student>();

}
Registrar::Registrar(int numOfWindows)
{
    m_time = 0;
    for (int i = 0; i < numOfWindows; i++)
    {
        m_windows.push_back(Window());
    }
    
    m_waitingQueue = new GenQueue<Student>();
}
//Deconstructor
Registrar::~Registrar()
{
    delete[] m_waitingQueue;
}
//Method
//Runs the simulation of the students arriving at the registrar
void Registrar::RunSimulation(vector<Student> students)
{
    
    //Run until the windows are empty no people in queue
    do
    {
        cout<<"Tick: "<<m_time<<endl;
        //Add students that are arriving to the queue
        for (int i = 0; i < students.size(); i++)
        {
            //If the student is arriving add it to the waiting queue
            if(students.at(i).getTimeArriving() == m_time)
            {
                cout << "Adding Student to Queue"<<endl;
                m_waitingQueue->insert(students.at(i));
            }
        }
        

        //If a window is open put that student there
        for (int i = 0; i < m_windows.size(); i++)
        {
            if(!m_windows.at(i).isUsed())
            {
                cout << "Adding Student to Window"<<endl;

                //If the window is not used then remove the first person waiting and add them to the open window
                Student s = m_waitingQueue->remove();
                m_windows.at(i).setStudent(&s);
            }
        }
        //Carry out Tick
        for (int i = 0; i < m_windows.size(); i++)
        {
            //Decreases the time for the person at the window
            //If there is no one at the window the window gains idle time
            //If the person has 0 ticks left then they leave the window which is signified by Decrement returning false
            if(!m_windows.at(i).Decrement())
            {
                cout << "Removing Student to Window"<<endl;
                //The student now leaves the window and is added to the total students vector
                //The window is now open
                m_students.push_back(*(m_windows.at(i).getStudent()));
                //Removes student from window
                m_windows.at(i).setStudent(0);
            }
        }
        //Add Waiting time to the students waiting in line 
        for (int i = 0; i < students.size(); i++)
        {
            //If the student is arriving add it to the waiting queue
            //WORK ON TRAVERSING THROUGH THE QUEUE AND HOW TO INCREMENT ALL OF THE ELEMENTS
        }
        m_time++;
        sleep(2);
    }
    while(!windowsAreEmpty() || !m_waitingQueue->isEmpty());
    
    

}
void Registrar::calculateStatistics()
{

}
bool Registrar::windowsAreEmpty()
{
    for (int i = 0; i < m_windows.size(); i++)
    {
        if(m_windows.at(i).isUsed())
        {
            return false;
        }
    }
    return true;
    
}