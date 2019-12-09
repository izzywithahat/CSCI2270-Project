# CSCI2270-Project
The purpose of this project is to take in a text file that builds a map with the use of a graph in order to find paths and then store the shortest paths in a priority list.
Compilation Command:
  g++ .\PathFinderUI.cpp .\PathFinder.cpp -o Path

Run Command: .\Path.exe

To select a map file(.txt) to find paths within, enter the name of the file when asked upon program initialization

Selecting option 1 at the menu will update the selected map file with a new user input file.
	Map.txt or Epstein.txt

Selecting option 2 displays a list of all found paths and their respective path lengths.

Selecting option 3 displays a list of all found paths and their respective path lengths. The user is then prompted to select a provided path. The corresponding path steps are printed, and the map file is printed with the selected path overwritten onto the map.

Selecting option 4 deconstructs the program and terminates. 
