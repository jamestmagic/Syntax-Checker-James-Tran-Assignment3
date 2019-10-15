#include "GenStack.h"
#include "Parsing.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv){
  //string location = argv[0];
  string fileName = argv[1];
  Parsing *p = new Parsing();
  p->readNewFile("hello", fileName);
  p->printFile();
  return 0;
}
