#include "GenStack.h"
#include "Parsing.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv){
  //string location = argv[0];
  string fileName = argv[1];
  Parsing *p = new Parsing();
  p->readNewFile(fileName);
  p->printFile();
  p->errorChecking();
  char answer = 'y';
  while(p->getCorrectSyntax() && answer == 'y'){
    cout << "Would you like to proccess another list?(y/n)" << endl;
    cin >> answer;
    if(towlower(answer) == 'y'){
      cout << "Please enter the name of your new file." << endl;
      cin >> fileName;
      p->readNewFile(fileName);
      p->printFile();
      p->errorChecking();
    }
  }
  return 0;
}
