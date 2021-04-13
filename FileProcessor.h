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
    void getFile(string inputFile);

};