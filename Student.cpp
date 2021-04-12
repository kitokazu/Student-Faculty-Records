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