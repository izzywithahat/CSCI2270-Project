#include "PathFinder.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
PathFinder PathFinder;

PathFinder::PathFinder()
{

}

PathFinder::~PathFinder()
{

}

void PathFinder::ConstructGraph(ifstream& inFile)
{

}

void PathFinder::SearchPaths()
{

}

void PathFinder::DisplayLL()
{
	int count = 0;
	LLPath* temp = head;
	while(temp != NULL)
	{
		cout << "Option: " << count << " Distance: " temp->dist << endl;
		temp = temp->next;
		count++;
	}
}

void PathFinder::DisplayPath(int index)
{

}

void PathFinder::SavePath(ifstream& inFile, int index)
{

}
