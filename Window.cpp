#include <iostream>
#include "Window.h"

using namespace std;

//Default Constructor
Window::Window()
{
    m_idleTime = 0;
    m_student = Student(-1,-1);
    hasStudent = false;
}
//Deconstructor
Window::~Window()
{
    //delete m_student;
}
//Getters
Student Window::getStudent()
{
    return m_student;
}
int Window::getIdleTime()
{
    return m_idleTime;
}
//Setters
void Window::setStudent(Student student)
{
    m_student = student;
    hasStudent = true;
}
void Window::setIdleTime(int time)
{
    m_idleTime = time;
}
//Methods
//Checks if the window is being used or not
bool Window::isUsed()
{
    if(hasStudent)
    {
        return true;
    }
    return false;
}
//Decrements the time left on the student at this window or increases the idle time for the window
bool Window::Decrement()
{
    if(!hasStudent)
    {
        m_idleTime++;
        return true;
    }
    else
    {
        //If time is 0 student = null else remove one tick from student 
        if(m_student.getTimeLeft() == 0)
        {
            hasStudent = false;
            return false;
        }
        else
        {
            cout << "Decreasing Time to: " << m_student.getTimeLeft()-1 << endl;
            m_student.setTimeLeft(m_student.getTimeLeft()-1);
            return true;
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