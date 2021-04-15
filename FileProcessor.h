//Header file for fileProcessor class
//Name: Luke Driscoll, Kai Itokazu
//Student ID Number: 2344496, 2344742
//Student Email: ldriscoll@chapman.edu, itokazu@chapman.edu
//Class: CPSC-350-01 - Prof. German
//Assignment 5: Registrars Office
#include <iostream>
#include <string>

using namespace std;

class FileProcessor{
  private:
    int num_windows;
  public:
    FileProcessor();
    ~FileProcessor();
    void getFile(string inputFile);

};