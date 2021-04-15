//Name: Luke Driscoll, Kai Itokazu
//Student ID Number: 2344496, 2344742
//Student Email: ldriscoll@chapman.edu, itokazu@chapman.edu
//Class: CPSC-350-01 - Prof. German
//Assignment 5: Registrars Office
#include "FileProcessor.h"
#include "Registrar.h"
#include "Student.h"
#include <iostream>
#include <string>
#include <fstream>

//using namespace std;

FileProcessor::FileProcessor() {
    int num_windows = 0;
};

FileProcessor::~FileProcessor() {

};

void FileProcessor::getFile(string inputFile) {
    //For input
    ifstream inFS;
    //String that holds the sentence from input file
    string fileSentence;


    inFS.open(inputFile);

    if(!inFS.is_open()) {
        cout << "Could not open file" << endl;
        return;
    }

    //Vector of students
    vector<Student> s;

    //string to get the num windows
    string windows;

    //Gets the first line which is the number of windows
    getline(inFS,windows);

    //the string windows converted into an int
    int num_windows = stoi(windows);

    //Goes through the file
    while(getline(inFS, fileSentence)) {

        //First line it sees is the arriving time 
        int tempTime = stoi(fileSentence);
        
        //The next line is the number of students, given time
        getline(inFS, fileSentence);
        int numStudents = stoi(fileSentence);

        //The next few lines are dependent on the number of students
        //Getting each student time depending on number of students
        for (int i = 0; i < numStudents; ++i) {
            getline(inFS, fileSentence);
            int studentTime = stoi(fileSentence);

            //Once it knows the arriving time and student time,
            //We can push it onto a new variable
            Student student = Student(studentTime,tempTime);

            //Pushes the student to a vector that is gonna be used for the simulation
            s.push_back(student);
        }
    }

    //Runnig the Simulation    
    Registrar *r = new Registrar(num_windows); 
    //Takes the vector of students as a parameter
    r->RunSimulation(s);
    r->calculateStatistics();

    if (!inFS.eof()) {
        cout << "input failure" << endl;
    }

    cout << "Closing file" << endl;

    inFS.close();

}


