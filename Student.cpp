//Name: Luke Driscoll, Kai Itokazu
//Student ID Number: 2344496, 2344742
//Student Email: ldriscoll@chapman.edu, itokazu@chapman.edu
//Class: CPSC-350-01 - Prof. German
//Assignment 5: Registrars Office
#include <iostream>
#include "Student.h"

using namespace std;

//Default Constructor
Student::Student(){}
//Overloading Constructor
Student::Student(int timeAtWindow, int timeArriving)
{
    m_totalTime = timeAtWindow;
    m_timeLeft = timeAtWindow;
    m_timeArriving = timeArriving;

}
//Deconstructor
Student::~Student(){}
//Getters
int Student::getTimeLeft()
{
    return m_timeLeft;
}
int Student::getTotalTime()
{
    return m_totalTime;
}
int Student::getTimeArriving()
{
    return m_timeArriving;
}
int Student::getTimeWaiting()
{
    return m_timeWaiting;
}
//Setters
void Student::setTimeLeft(int time)
{
    m_timeLeft = time;
}
void Student::setTotalTime(int time)
{
    m_totalTime = time;
}
void Student::setTimeArriving(int time)
{
    m_timeArriving = time;
}
void Student::setTimeWaiting(int time)
{
    m_timeWaiting = time;
}
bool Student::operator == (Student s)
{
    //Checks if the variables are the same
    if((m_timeArriving == s.m_timeArriving) && (m_timeLeft == s.m_timeLeft) && (m_totalTime == s.m_totalTime) && (m_timeWaiting == s.m_timeWaiting))
    {
        return true;
    }
    return false;
}
bool Student::operator != (Student s)
{
    //Checks if the variables are not the same
    if((m_timeArriving != s.m_timeArriving) || (m_timeLeft != s.m_timeLeft) || (m_totalTime != s.m_totalTime) || (m_timeWaiting != s.m_timeWaiting))
    {
        return true;
    }
    return false;
}