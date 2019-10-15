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
int numDelimiters; //total number of delimiters in source file
GenStack<char> *gs; //stack
string newFile; //string used to represent source file
int numOpenBrackets = 0; //number of open brackets
int numCloseBrackets = 0; //number of close brackets
int numOpenParen = 0; //number of open parentheses
int numCloseParen = 0; //number of close parentheses
int numOpenCurly = 0; //number of open curly brackets
int numCloseCurly = 0; //number of close curly brackets
int numLines = 0; //how many lines in the file
bool correctSyntax = true;

Parsing::Parsing(){ //default constructor
  lineNum = 1;
  numDelimiters = 0;
  gs =new GenStack<char>(10);
  newFile = "";
}

Parsing::~Parsing(){ //destructor
  delete gs;
}

void Parsing::readNewFile(string fileName){ //copies cource file code into newFile string
  ifstream readFile(fileName);
  string tempString;
  try{
    if(!readFile){ //checks if readfile exists
      throw readFile;
    }
    while(getline(readFile, tempString)){ //iterate through
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
    if(checkIfDelimiter(newFile[i])){ //if the character is a delmiter, the delimiter is added to the stack
      addDelimiter(newFile[i]);
      ++numDelimiters;
      //General cases for mismatched delimiters
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
      gs->push(newFile[i]); //adds current delimiter to stack
    }
    if(newFile[i] == '\n'){
      ++lineNum;//keeps track of which line an error may be on
    }
  }
  gs->setSize(numDelimiters); //matches sizes
  if(correctSyntax){ //if the syntax is correct
    cout << "All Delimiter Syntax is correct." << endl;
  }
}

void Parsing::printFile(){ //prints the file
  cout << newFile << endl;
}

bool Parsing::checkIfDelimiter(char c){ //checks if the char parameter is a delimiter
  if(c == '[' || c == ']' || c == '(' || c == ')' || c == '{' || c == '}'){
    return true;
  }
  else{
    return false;
  }
}

void Parsing::addDelimiter(char c){//adds to respective count of each type of delimiter
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

void Parsing::printError(int lineNumber, char expected, char found){ //prints the error
  if(lineNumber == numLines && numOpenCurly > numCloseCurly){
    cout << "Error: Reached end of file: missing }" << endl;
  }
  else{
    string s = "Error: Line " + to_string(lineNumber) + ": expected " + expected + " and found " + found + "";
    cout << s << endl;
  }
  correctSyntax = false;
}

bool Parsing::getCorrectSyntax(){ //accessor for correctSyntax
  return correctSyntax;
}
