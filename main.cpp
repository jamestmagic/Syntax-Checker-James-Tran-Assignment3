#include "GenStack.h"
#include "Parsing.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv){
  string fileName = argv[1];
  Parsing *p = new Parsing(); //new parsing object
  p->readNewFile(fileName);
  p->errorChecking(); //runs error checking and iteration
  char answer = 'y';
  while(p->getCorrectSyntax() && answer == 'y'){ //asks if new
    cout << "Would you like to proccess another list?(y/n)" << endl;
    cin >> answer;
    if(towlower(answer) == 'y'){
      cout << "Please enter the name of your new file." << endl;
      cin >> fileName;
      p->readNewFile(fileName);
      p->errorChecking();
    }
  }
  return 0;
}
