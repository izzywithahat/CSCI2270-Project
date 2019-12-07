#include "PathFinder.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void menu(){
	cout << "======Main Menu======" << endl;
	cout << "1. Change the Map File (.txt)" << endl;
	cout << "2. Display List of Path Lengths" << endl;
  cout << "3. Select and Display Path" << endl;
  cout << "4. Output Map with Selected Path" <<endl;
	cout << "5. Quit" << endl;
}

int main()
{
PathFinder PathFinder;
string input;
bool run = true;
int index;
ifstream inFile;

cout << "Enter Input Map File (.txt)" << endl;
getline(cin,input);
inFile.open(input);

while(!inFile.is_open()){
  cout << "Invalid Input File, please enter valid Input File (.txt)" << endl;
  cout << "Enter Input Map File (.txt)" << endl;
  getline(cin,input);
  inFile.open(input);;
}
PathFinder.ConstructGraph(inFile);
PathFinder.SearchPaths();

while(run){
  menu();
  getline(cin,input);
  switch(stoi(input)){

    case 1: //Change the Map File (.txt)
      cout << "Enter Input Map File (.txt)" << endl;
      getline(cin,input);
      inFile.open(input);

      while(!inFile.is_open()){
        cout << "Invalid Input File, please enter valid Input File (.txt)" << endl;
        cout << "Enter Input Map File (.txt)" << endl;
        getline(cin,input);
        inFile.open(input);;
      }
      PathFinder.ConstructGraph(inFile); //Create Graph From Input inFile
      PathFinder.SearchPaths(); //Breadth First Search and Sort Paths in Priority Queue
      run=true;
    break;

    case 2: //Display List of Path Lengths
      PathFinder.DisplayLL();
      run=true;
    break;

    case 3: //Select and Display Path
      PathFinder.DisplayLL();
      cout << "Enter the index number of the Path you would like to take" << endl;
      getline(cin,input);
      index=stoi(input);
      PathFinder.DisplayPath(index);
      run=true;
    break;

    case 4: //Output Map with Selected Path
    PathFinder.DisplayLL();
      cout << "Enter the index number of the Path you would like to take" << endl;
      getline(cin,input);
      index=stoi(input);
      PathFinder.SavePath(inFile, index);
      run=true;
    break;

    case 5: //Quit
      cout << "Goodbye!" << endl;
      run=false;
      inFile.close();
      PathFinder.~PathFinder();
    break;
    default:
      cout << "Invalid Input" << endl;
      run=true;
    break;
    }
  }
}
