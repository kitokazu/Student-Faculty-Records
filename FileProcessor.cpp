#include "FileProcessor.h"
#include "Registrar.h"

#include <iostream>
#include <string>
#include <fstream>

//using namespace std;

FileProcessor::FileProcessor() {
    int num_windows = 0;
};

FileProcessor::~FileProcessor() {

};

string FileProcessor::getFile(string inputFile) {
    //For input
    ifstream inFS;
    //String that holds the sentence from input file
    string fileSentence;


    inFS.open(inputFile);

    if(!inFS.is_open()) {
        cout << "Could not open file" << endl;
        return "";
    }

    string windows;
    getline(inFS,windows);
    int num_windows = stoi(windows);

    while(getline(inFS, fileSentence)) {
        int temp = stoi(fileSentence);

    }

    if (!inFS.eof()) {
        cout << "input failure" << endl;
    }

    cout << "Closing file" << endl;

    inFS.close();

}


