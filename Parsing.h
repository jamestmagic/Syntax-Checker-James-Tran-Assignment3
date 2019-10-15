#include <iostream>
#include "GenStack.h"

using namespace std;

class Parsing{
private:
  int lineNum;
  int numDelimiters;
  GenStack<char> *gs;
  string newFile;

public:
  Parsing();
  ~Parsing();
  void readNewFile(string fileName);
  void errorChecking();
  void printFile();
  bool checkIfDelimiter(char c);
  void addDelimiter(char c);
  void printError(int lineNumber, char expected, char found);
  bool getCorrectSyntax();
};
