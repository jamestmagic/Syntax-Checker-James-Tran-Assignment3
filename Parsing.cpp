#define _USE_MATH_DEFINES
#include "Parsing.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <cmath>
#include <time.h>

using namespace std;

int lineNum;
int numBrackets;
GenStack<char> *gs;
string newFile;

Parsing::Parsing(){
  lineNum = 1;
  numBrackets = 0;
  gs =new GenStack<char>(10);
  newFile = "";
}

Parsing::~Parsing(){

}

void Parsing::readNewFile(string path, string fileName){
  try{
    // string directory;
    // const size_t last_slash_idx = path.rfind('\\');
    // if (std::string::npos != last_slash_idx)
    // {
    //     directory = path.substr(0, last_slash_idx);
    // }
    ifstream readFile(fileName);
    string tempString;
    while(getline(readFile, tempString)){
      newFile += tempString;
      newFile += "\n";
    }
  }
  catch(ifstream::failure e){ //throws expection in case of ioexception
    cout << "Exception: Could not read or open file" << endl;
  }



}


void Parsing::errorChecking(){
  for(int i = 0;i<newFile.length();++i){
    if(checkIfDelimiter(newFile[i])){
      gs->push(newFile[i]);
      ++numBrackets;
    }
  }
  for(int i = 0;i<numBrackets;++i){
    
  }

}

void Parsing::printFile(){
  cout << newFile << endl;
}

bool Parsing::checkIfDelimiter(char c){
  if(c == '[' || c == ']' || c == '(' || c == ')' || c == '{' || c == '}'){
    return true;
  }
  else{
    return false;
  }
}
