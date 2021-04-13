#include <iostream>
#include "Window.h"

using namespace std;

//Default Constructor
Window::Window()
{
    m_idleTime = 0;
    m_student = 0;
}
//Deconstructor
Window::~Window()
{
    delete m_student;
}
//Getters
Student* Window::getStudent()
{
    return m_student;
}
int Window::getIdleTime()
{
    return m_idleTime;
}
//Setters
void Window::setStudent(Student *student)
{
    m_student = student;
}
void Window::setIdleTime(int time)
{
    m_idleTime = time;
}
//Methods
//Checks if the window is being used or not
bool Window::isUsed()
{
    if(m_student == 0)
    {
        return false;
    }
    return true;
}
//Decrements the time left on the student at this window or increases the idle time for the window
Student* Window::Decrement()
{
    if(m_student == 0)
    {
        m_idleTime++;
    }
    else
    {
        //If time is 0 student = null else remove one tick from student 
        if(m_student->getTimeLeft() == 0)
        {
            return m_student;
            
        }
        else
        {
            m_student->setTimeLeft(m_student->getTimeLeft()-1);
            return 0;
        }
        
    }
    
    
}
bool Window::operator == (Window w)
{
    //Checks if the variables are the same
    if(m_student == w.m_student && m_idleTime == w.m_idleTime)
    {
        return true;
    }
    return false;
}
bool Window::operator != (Window w)
{
    //Checks if the variables are the same
    if(m_student != w.m_student || m_idleTime != w.m_idleTime)
    {
        return true;
    }
    return true;
}