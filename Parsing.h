#include <iostream>
#include "GenStack.cpp"

using namespace std;

class Parsing{
private:
  int lineNum;
  int numBrackets;
  GenStack<char> *gs;
  string newFile;

public:
  Parsing();
  ~Parsing();
  void readNewFile(string path, string fileName);
  void errorChecking();
  void printFile();
  bool checkIfDelimiter(char c);
};
