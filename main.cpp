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