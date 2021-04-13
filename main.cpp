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
    s.push_back(Student(1,0));
    s.push_back(Student(1,1));
    s.push_back(Student(2,2));
    Registrar *r = new Registrar(2); 
    r->RunSimulation(s);
}