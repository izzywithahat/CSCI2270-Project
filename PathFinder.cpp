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

bool searchHelper(Path* node, char Que[], int dist, char StepDir)
{
  
  //If at end -> save Que to
  if(node->type==3){
    saveNode(newQue,dist);
    //WE DID IT
  }
  else{
    searchHelper(node->NChild, newQue, dist+1)
    searchHelper(node->WChild, newQue, dist+1)
    searchHelper(node->SChild, newQue, dist+1)
    searchHelper(node->EChild, newQue, dist+1)
  }

}

void PathFinder::SearchPaths(Path* root)
{
  searchHelper(root);
	/*create dynamic array at root
	 copy and add to array at each step
	 if 3 is found copy to linked list then deallocate
	 else deallocate */
  //IZZY's Code vvv
  /*
	bool found = false;
	int capacity = 50;
	Path* temp = root;
	PathQ* temp2;
	temp2 = new PathQ[capacity];

	while(found)
	{
		if(temp->WChild == 3 || temp->SChild == 3 || temp->EChild == 3 || temp->NChild == 3)
		{

			found = true;
		}
		else
		{

		}
	}
  */


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
