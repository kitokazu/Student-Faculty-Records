#include <string>
#include <iostream>
#include "GenQueue.h"
#include "Registrar.h"

using namespace std;

int main(int argc, char **agrv) {
    GenQueue<Student> *queue = new GenQueue<Student>;
    queue->insert(Student(0,0));
    queue->insert(Student(5,5));
    queue->insert(Student(1,1));
    cout << queue->remove().getTimeArriving() << endl;
    cout << queue->remove().getTimeArriving() << endl;
    cout << queue->remove().getTimeArriving() << endl;
    delete queue;


    
    vector<Student> s;
    Student st = Student(5,1);
    Student stu = Student(10,1);
    Student stud = Student(4,3);
    
    s.push_back(st);
    s.push_back(stu);
    s.push_back(stud);
    Registrar *r = new Registrar(5); 
    r->RunSimulation(s);
}