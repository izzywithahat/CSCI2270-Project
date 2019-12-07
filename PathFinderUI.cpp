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
{ /*
	string find, title, input, del;
	ifstream inFile(argv[1]);
	inFile.is_open();
*/
PathFinder PathFinder;
string input;
bool run = true;

cout << "Enter Input Map File (.txt)" << endl;
getline(cin,input);
ifstream inFile(input);

while(!inFile.is_open()){
  cout << "Invalid Input File, please enter valid Input File (.txt)" << endl;
  cout << "Enter Input Map File (.txt)" << endl;
  getline(cin,input);
  ifstream inFile(input);
}
PathFinder.ConstructGraph(inFile);

while(run){
  menu();
  getline(cin,input);
  switch(stoi(input)){

    case 1: //Change the Map File (.txt)
      cout << "Enter Input Map File (.txt)" << endl;
      getline(cin,input);
      ifstream inFile(input);

      while(!inFile.is_open()){
        cout << "Invalid Input File, please enter valid Input File (.txt)" << endl;
        cout << "Enter Input Map File (.txt)" << endl;
        getline(cin,input);
        ifstream inFile(input);
      }
      PathFinder.ConstructGraph(inFile);

      run=true;
    break;

    case 2: //Display List of Path Lengths

      run=true;
    break;

    case 3: //Select and Display Path
      run=true;
    break;

    case 4: //Output Map with Selected Path
      run=true;
    break;

    case 5: //Quit
      cout << "Goodbye!" << endl;
      run=false;
      inFile.close();
    break;
    default:
      cout << "Invalid Input" << endl;
      run=true;
    break;
    }
  }
}
