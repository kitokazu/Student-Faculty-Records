//Header file for fileProcessor class
#include <iostream>
#include <string>

using namespace std;

class FileProcessor{
  private:
    int num_windows;
  public:
    FileProcessor();
    ~FileProcessor();
    string getFile(string inputFile);
    string writeFile(string outputFile);

};