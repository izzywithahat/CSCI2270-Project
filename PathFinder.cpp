#include "PathFinder.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
PathFinder PathFinder;

PathFinder::PathFinder(){}

PathFinder::~PathFinder(){}

Path* PathFinder::ConstructGraph(ifstream& inFile)
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

void searchHelper(Path* node, char Que[], int xCrumb[], int yCrumb[], int dist, char StepDir)
{
	dist++;                              //Increase Distance by one step
	char newQue    = new  char[dist];    //Allocate new Queue
	int  newxCrumb = new  int[dist];
	int  newyCrumb = new  int[dist];

	for(int i = 0; i < dist-1; i++) 	//Copy Old Queue & Breadcrumb Trail
	{
		newQue[i] = Que[i];
    	newxCrumb[i] = xCrumb[i];
    	newyCrumb[i] = yCrumb[i];
    }

    newQue[dist-1] = StepDir;       //Update Queue with new Step
    newxCrumb[dist-1] = node->x;    //Update Breadcrumb Trail with New Postion
    newyCrumb[dist-1] = node->y;    //Update Breadcrumb Trail with New Postion


	//If at end -> save newQue to LL
	if(node->type == 3)
    {
		saveNode(newQue,dist);
	    //WE DID IT
	}
	else
	{
      int flag = 0;
      int i = 0;
		  if (StepDir == 'N' || node->NChild->type != 1) flag = 1;
      for(i = 0; i < dist; i++) 
      	if(node->NChild->x == newxCrumb[i] && node->NChild->y == newyCrumb[i]) 
      		flag = 1;
      if (flag=0) searchHelper(node->NChild, newQue, dist, 'N');
      	flag = 0;

	    if(StepDir != 'W' && node->WChild->type != 1 && node->WChild->type != 2) searchHelper(node->WChild, newQue, dist, 'W');
	    if(StepDir != 'S' && node->SChild->type != 1 && node->SChild->type != 2) searchHelper(node->SChild, newQue, dist, 'S');
	    if(StepDir != 'E' && node->EChild->type != 1 && node->EChild->type != 2) searchHelper(node->EChild, newQue, dist, 'E');
	}
	delete [] newQue;
  	delete [] newxCrumb;
  	delete [] newyCrumb;
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
		cout << "Path Number: " << count << " Path Distance: " temp->dist << endl;
		temp = temp->next;
		count++;
	}
}

void PathFinder::DisplayPath(int index, Path mat[][])
{
	LLPath *temp = head;
	for(int i = 0; i < index; i++)
	{
		temp = temp->next;
	}
	cout << "Path Number: " << index << endl;
	cout << "Path Distance: " << temp << endl;
	cout << "Path directions from 2 to 3" << endl;
	cout << "Start: 2" << endl;
	for(int j = 0; j < Link2U->arrEnd; j++)
	{
		cout << temp->Link2U->arrQ[j] << endl;
	}
	cout << "End: 3" << endl;

	Path* ptr = root;
	char matS[18][16];
	for(int i = 0; i < 16; i++)
	{
		for(int j = 0; j < 18; j++)
		{
			if(mat[j][i]->type == 0)
			{
				matS[j][i] = '0';
			}
			else if(mat[j][i]->type == 1)
			{
				matS[j][i] = '1';
			}
			else if(mat[j][i]->type == 2)
			{	
				matS[j][i] = '2';
			}
			else if(mat[j][i]->type == 3)
			{
				matS[j][i] = '3';
			}
			//ptr = ptr->next;
		}
	}


}

void PathFinder::SavePath(ifstream& inFile, int index)
{

}
