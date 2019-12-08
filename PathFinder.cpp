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
  string line;
  string token;
  int x = 0;
  int y = 0;
  Path mat[18][16];
  while(getline(inFile, line)) //Copy Map File onto Graph Matrix
  {
    stringstream ss(line);
    while(ss >> token)
    {
      mat[y][x]->type = token;
      mat[y][x]->x = x;
      mat[y][x]->y = y;
      x++;
    }
    y++;
  }
  //Create Graph From Matrix
  for(x = 0; x < 16; x++)
  {
    for(y = 0; y < 18; y++)
    {
      if(x - 1 >= 0)
        mat[y][x]->WChild = mat[y][x-1];
      if(x + 1 < 16)
        mat[y][x]->EChild = mat[y][x+1];
      if(y - 1 >= 0)
        mat[y][x]->NChild = mat[y-1][x];
      if(y + 1 < 18)
        mat[y][x]->SChild = mat[y+1][x];
    }
  }
}

void searchHelper(Path* node, char Que[], int dist, char StepDir)
{
	dist++;                         //Increase Distance by one step
	char newQue = new char[dist];   //Allocate new Queue
	for(int i = 0; i < dist-1; i++) //Copy Old Queue
		newQue[i] = Que[i];
	newQue[dist-1] = StepDir;       //Update Queue with new Step

	//If at end -> save newQue to LL
	if(node->type == 3)
    {
		saveNode(newQue,dist);
	    //WE DID IT
	}
	else
	{
		if(StepDir != 'N' && node->NChild->type != 1 && node->NChild->type != 2) searchHelper(node->NChild, newQue, dist, 'N');
	    if(StepDir != 'W' && node->WChild->type != 1 && node->WChild->type != 2) searchHelper(node->WChild, newQue, dist, 'W');
	    if(StepDir != 'S' && node->SChild->type != 1 && node->SChild->type != 2) searchHelper(node->SChild, newQue, dist, 'S');
	    if(StepDir != 'E' && node->EChild->type != 1 && node->EChild->type != 2) searchHelper(node->EChild, newQue, dist, 'E');
	}
	delete [] newQue;
}

void PathFinder::SearchPaths(Path* root)
{
  searchHelper(root);
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
	LLPath *temp = root;
	for(int i = 0; i < index; i++)
	{
		
	}
		// while(temp->next != NULL)
		// {
		// 	cout << temp->dist
		// }

}

void PathFinder::SavePath(ifstream& inFile, int index)
{

}
