#define _USE_MATH_DEFINES
#include "Parsing.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <cmath>
#include <time.h>

using namespace std;

int lineNum; //which line in file
int numDelimiters;
GenStack<char> *gs;
string newFile;
int numOpenBrackets = 0;
int numCloseBrackets = 0;
int numOpenParen = 0;
int numCloseParen = 0;
int numOpenCurly = 0;
int numCloseCurly = 0;
int numLines = 0; //how many lines in the file
bool correctSyntax = true;

Parsing::Parsing(){
  lineNum = 1;
  numDelimiters = 0;
  gs =new GenStack<char>(10);
  newFile = "";
}

Parsing::~Parsing(){

}

void Parsing::readNewFile(string fileName){
  ifstream readFile(fileName);
  string tempString;
  try{
    if(!readFile){
      throw readFile;
    }
    while(getline(readFile, tempString)){
      newFile += tempString;
      newFile += "\n";
      ++numLines;
    }
  }
  catch(exception& e){ //throws expection in case of ioexception
    cout << "Exception: Could not read or open file" << endl;
  }

}


void Parsing::errorChecking(){
  for(int i = 0;i<newFile.length();++i){
    if(checkIfDelimiter(newFile[i])){
      addDelimiter(newFile[i]);
      ++numDelimiters;
      if(newFile[i] == ']' && (numOpenBrackets < numCloseBrackets) && i>0){
        printError(lineNum, '[', gs->peek());
        break;
      }
      else if(newFile[i] == ')' && (numOpenParen < numCloseParen) && i>0){
        printError(lineNum, '(', gs->peek());
        break;
      }
      else if(newFile[i] == '}' && (numOpenCurly < numCloseCurly) && i>0){
        printError(lineNum, '{', gs->peek());
        break;
      }
      else if((newFile[i] == '}' || newFile[i] == '{') && (((numOpenBrackets+numCloseBrackets)%2) != 0)){
        printError(lineNum, ']', gs->peek());
        break;
      }
      else if((newFile[i] == '}' || newFile[i] == '{') && (((numOpenParen+numCloseParen)%2) != 0)){
        printError(lineNum, ')', gs->peek());
        break;
      }
      else if((newFile[i] == '}' || newFile[i] == '{') && (((numOpenParen+numCloseParen)%2) != 0)){
        printError(lineNum, ')', gs->peek());
        break;
      }
      else if(lineNum == numLines && numOpenCurly > numCloseCurly){
        printError(lineNum, '}', gs->peek());
        break;
      }
      gs->push(newFile[i]);
    }
    if(newFile[i] == '\n'){
      ++lineNum;
    }
  }
  gs->setSize(numDelimiters);
  if(correctSyntax){
    cout << "All Delimiter Syntax is correct." << endl;
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

void Parsing::addDelimiter(char c){
  if(c == '['){
    ++numOpenBrackets;
  }
  else if(c == ']'){
    ++numCloseBrackets;
  }
  else if(c == '('){
    ++numOpenParen;
  }
  else if(c == ')'){
    ++numCloseParen;
  }
  else if(c == '{'){
    ++numOpenCurly;
  }
  else if(c == '}'){
    ++numCloseCurly;
  }
}

void Parsing::printError(int lineNumber, char expected, char found){
  if(lineNumber == numLines && numOpenCurly > numCloseCurly){
    cout << "Reached end of file: missing }" << endl;
  }
  else{
    string s = "Line " + to_string(lineNumber) + ": expected " + expected + " and found " + found + "";
    cout << s << endl;
  }
  correctSyntax = false;
}

bool Parsing::getCorrectSyntax(){
  return correctSyntax;
}
