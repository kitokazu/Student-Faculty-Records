//Name: Luke Driscoll, Kai Itokazu
//Student ID Number: 2344496, 2344742
//Student Email: ldriscoll@chapman.edu, itokazu@chapman.edu
//Class: CPSC-350-01 - Prof. German
//Assignment 5: Registrars Office
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
    //Add windows according to the parameter
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
        //Add students that are arriving to the queue
        for (int i = 0; i < students.size(); i++)
        {
            //If the student is arriving add it to the waiting queue
            if(students.at(i).getTimeArriving() == m_time)
            {
                m_waitingQueue->insert(students.at(i));
            }
        }
        

        //If a window is open put that student there
        for (int i = 0; i < m_windows.size(); i++)
        {
            //if any window is open and people are in line
            if(!m_windows.at(i).isUsed() && !m_waitingQueue->isEmpty())
            {

                //If the window is not used then remove the first person waiting and add them to the open window
                Student s = m_waitingQueue->remove();
                m_windows.at(i).setStudent(s);
                
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
                //The student now leaves the window and is added to the total students vector
                //The window is now open
                m_students.push_back(m_windows.at(i).getStudent());
            }
        }
        //Add Waiting time to the students waiting in line 
        for (int i = 0; i < m_waitingQueue->getSize(); i++)
        {
            //If the student is waiting then increment it
            //To traverse we remove front increment and then add it back to the end
            Student s = m_waitingQueue->remove();
            s.setTimeWaiting(s.getTimeWaiting()+1);
            m_waitingQueue->insert(s);
            
        }
        m_time++;
    }
    while(!windowsAreEmpty() || !m_waitingQueue->isEmpty() || m_students.size() != students.size());
    
    

}
void Registrar::calculateStatistics()
{
    //Sort Students to allow us to find the median
    for (int i = 0; i < m_students.size(); i++)
    {
        for (int j = 0; j < m_students.size()-i-1; j++)
        {
            if(m_students.at(j).getTimeWaiting() > m_students.at(j+1).getTimeWaiting())
            {
                Student s = m_students.at(j);
                m_students.at(j) = m_students.at(j+1);
                m_students.at(j+1) = s;
            }
        }
    }
    //Getting the Mean
    double sum = 0;
    for(int i = 0; i < m_students.size(); i++)
    {
        sum += m_students.at(i).getTimeWaiting();
    }
    cout << "1. The mean student wait time is " << sum/m_students.size() << " ticks" << endl;
    //Getting the median from the sorted list
    double median;
    //If the size is even find average between middle two values
    if(m_students.size() % 2 == 0)
    {
        median = m_students.at(m_students.size()/2 - 1).getTimeWaiting() + m_students.at(m_students.size()/2).getTimeWaiting();
        median /= 2;
    }
    else
    {
        median = m_students.at(m_students.size()/2).getTimeWaiting();
    }
    
    cout << "2. The median student wait time is " << median << " ticks" << endl;
    //Getting Longest wait time
    cout << "3. The longest student wait time is " << m_students.at(m_students.size() - 1).getTimeWaiting() << " ticks" << endl;
    //Getting number of students waiting more than 10 seconds
    int numStudentsWaiting = 0;
    for(int i = 0; i < m_students.size(); i++)
    {
        if(m_students.at(i).getTimeWaiting() > 10)
        {
            numStudentsWaiting++;
        }
    }
    cout << "4. The number of students waiting over 10 minutes is " << numStudentsWaiting << " students" << endl;
    //Getting the mean window time
    double windowSum = 0;
    for(int i = 0; i < m_windows.size(); i++)
    {
        windowSum += m_windows.at(i).getIdleTime();
    }
    cout << "5. The mean window idle time is " << windowSum/m_windows.size() << " ticks" << endl;
    //Getting the longest window idle time
    int longestWaitTime = -1;
    for(int i = 0; i < m_windows.size(); i++)
    {
        if(longestWaitTime < m_windows.at(i).getIdleTime())
        {
            longestWaitTime = m_windows.at(i).getIdleTime();
        }
    }
    cout << "6. The longest window idle time is " << longestWaitTime << " ticks" << endl;
    //Getting the windows with over 5 ticks of idle time
    int numWindowsIdle = 0;
    for(int i = 0; i < m_windows.size(); i++)
    {
        if(m_windows.at(i).getIdleTime() > 5)
        {
            numWindowsIdle++;
        }
    }
    cout << "7. Number of windows idle for over 5 minutes is " << numWindowsIdle << " windows" << endl;





    

}
//Checks if all the windows are empty
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