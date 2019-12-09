#include "PathFinder.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

/*
  * This is a menu that allows the users to choose what it is they want to do with their map
*/

void menu()
{
	cout << "======Main Menu======" << endl;
	cout << "1. Change the Map File (.txt)" << endl;
	cout << "2. Display List of Path Lengths" << endl;
  cout << "3. Select and Display Path" << endl;
  cout << "4. Quit" << endl;
}

int main()
{
  PathFinder PathFinder;    // Makes a PathFInder object
  string input;
  bool run = true;
  int index;
  ifstream inFile;

  cout << "Enter Input Map File (.txt)" << endl;  // Prompts users for a file
  getline(cin, input);                            // Takes every line in from the file
  inFile.open(input);                             // Opens the file and gets the data

  while(!inFile.is_open())                        // Checks if the file actually opened
  {
    cout << "Invalid Input File, please enter valid Input File (.txt)" << endl;   // If file did not open asks for a different one
    getline(cin, input);                                                          // Takes every line in from the file
    inFile.open(input);                                                           // Opens the file and gets the data
  }

  Path* temp;                             // Creates a temp variable that has the attributes of Path
  Path* mat[18][16] = {};                 // Creates an array with the path attributes, an array of pointers
	PathFinder.ConstructGraph(inFile, mat); // Calls the function in order to construct the map using the input file

  for(int i = 0; i < 16; i++)             // These for loops traverse in order to find where the starting point is (2)
  {
    for(int j = 0; j < 18; j++)
    {
      if(mat[j][i]->type == 2)
        temp = mat[j][i];
    }
  }

  PathFinder.SearchPaths(temp);           // Calls the search path function and passes through the root in order to find all feasable paths

  while(run)            // Continues to loop as long as the user does not quit
  {
    menu();             // Calls menu function
    getline(cin,input); // Gets the user input from the menu options
    switch(stoi(input)) // Takes the input and makes it an int to go to different cases
    {
      case 1: //Change the Map File (.txt)
        cout << "Enter Input Map File (.txt)" << endl;  // Prompts users for a file
        getline(cin, input);                            // Takes every line in from the file
        inFile.open(input);                             // Opens the file and gets the data

        while(!inFile.is_open())                        // Checks if file was opened
        {
          cout << "Invalid Input File, please enter valid Input File (.txt)" << endl; // If file did not open asks for a different one
          getline(cin, input);                                                        // Takes every line in from the file
          inFile.open(input);                                                         // Opens the file and gets the data
        }
        PathFinder.ConstructGraph(inFile, mat);                                       // Create Graph From Input inFile
        PathFinder.SearchPaths(temp);                                                 // Breadth First Search and Sort Paths in Priority Queue
        run = true;                                                                   // Sets run to true
      break;                                                                          // Goes back into the while loop and leaves case

      case 2: //Display List of Path Lengths
        PathFinder.DisplayLL();                                                       // Calls the Display function for LL to see the paths
        run = true;                                                                   // Sets run to true
      break;                                                                          // Goes back into the while loop and leaves case

      case 3: //Select and Display Path
        PathFinder.DisplayLL();                                                       // Calls the Display function for LL to see the paths
        cout << "Enter the index number of the Path you would like to take" << endl;  // Prompts user for which path they would want to take
        getline(cin, input);                                                          // Takes in the user input
        index = stoi(input);                                                          // Takes the input and makes it an interger
        PathFinder.DisplayPath(index, mat);                                           // Passes through the index and 2D array to call display funtion
        run = true;                                                                   // Sets run to true
      break;                                                                          // Goes back into the while loop and leaves case

      case 4: //Quit
        cout << "Goodbye!" << endl;                                                   // Tells the user Adios
        run = false;                                                                  // Sets run to false
        inFile.close();                                                               // Closes the file
      break;                                                                          // Breaks from the case statement

      default:
        cout << "Invalid Input" << endl;                                              // Tells user if their input is valid or not
        run = true;                                                                   // Sets run to true
      break;                                                                          // Breaks from default case statement
    }
  }
}
