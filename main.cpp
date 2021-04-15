//Name: Luke Driscoll, Kai Itokazu
//Student ID Number: 2344496, 2344742
//Student Email: ldriscoll@chapman.edu, itokazu@chapman.edu
//Class: CPSC-350-01 - Prof. German
//Assignment 5: Registrars Office
#include <string>
#include <iostream>
#include "GenQueue.h"
#include "Registrar.h"
#include "FileProcessor.h"

using namespace std;

int main(int argc, char **argv) {
    //if the user does not enter the correct command line parameters
    if (argc != 2) {
        cerr << "Error. Please enter the input file"<< endl;
        return -1;
    }

    //input file name
    string inputFile = argv[1];

    FileProcessor *test = new FileProcessor;
    test->getFile(inputFile);
}