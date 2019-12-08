#include "PathFinder.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
PathFinder PathFinder;

PathFinder::PathFinder(){}

PathFinder::~PathFinder(){}

Path** PathFinder::ConstructGraph(ifstream& inFile)
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
  return mat;
}

void searchHelper(Path* node, char Que[], int xCrumb[], int yCrumb[], int dist, char StepDir)
{
	dist++;                              //Increase Distance by one step
	char newQue    = new  char[dist];    //Allocate new Queue
	int  newxCrumb = new  int[dist];
	int  newyCrumb = new  int[dist];

	for(int i = 0; i < dist-1; i++) 	   //Copy Old Queue & Breadcrumb Trail
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
		saveNode(newQue,newxCrumb,newyCrumb,dist);
	    //WE DID IT
	}
	else
	{
      int flag = 0;
      int i = 0;

      //TAKE A STEP NORTH
		  if (node->NChild->type == 1 || !node->NChild) flag = 1;
      for(i = 0; i < dist; i++)
      	if(node->NChild->x == newxCrumb[i] && node->NChild->y == newyCrumb[i])
      		flag = 1;
      if (flag == 0) searchHelper(node->NChild, newQue, newxCrumb, newyCrumb, dist, 'N');
      	flag = 0;
      //TAKE A STEP WEST
      if (node->WChild->type == 1 || !node->WChild) flag = 1;
      for(i = 0; i < dist; i++)
        if(node->WChild->x == newxCrumb[i] && node->WChild->y == newyCrumb[i])
          flag = 1;
      if (flag == 0) searchHelper(node->WChild, newQue, newxCrumb, newyCrumb, dist, 'W');
        flag = 0;
      //TAKE A STEP SOUTH
      if (node->SChild->type == 1 || !node->SChild) flag = 1;
      for(i = 0; i < dist; i++)
      	if(node->SChild->x == newxCrumb[i] && node->SChild->y == newyCrumb[i])
      		flag = 1;
      if (flag == 0) searchHelper(node->SChild, newQue, newxCrumb, newyCrumb, dist, 'N');
      	flag = 0;
      //TAKE A STEP EAST
      if (Sode->EChild->type == 1 || !node->EChild) flag = 1;
      for(i = 0; i < dist; i++)
       if(node->EChild->x == newxCrumb[i] && node->EChild->y == newyCrumb[i])
         flag = 1;
      if (flag == 0) searchHelper(node->EChild, newQue, newxCrumb, newyCrumb, dist, 'E');
       flag = 0;
    }
	delete [] newQue;
  	delete [] newxCrumb;
  	delete [] newyCrumb;
}

void PathFinder::SearchPaths(Path* root)
{
  char Que[1] = {};
  int  xCrumb[1] = {root->x};
  int  yCrumb[1] = {root->y};
  int  dist = 0;
  char StepDir = '*';
  searchHelper(root, Que[], xCrumb[], yCrumb, dist, StepDir);
}

/*
	* This function prints the Linked list with the number of the path as well as how long that path is.
*/

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

/*
	* The Purpose of this function is to display the path first directionally, the steps to get from A to B or in this case 2 to 3.
	* It the takes in the node 2D matrix and changes everything to a character 2D array and diplays the path, '*', on the matrix.
	* This is the printed off so the user has the directions and a map of the path.
*/ 

void PathFinder::DisplayPath(int index, Path mat[][])
{
	LLPath *temp = head;							// Defines a temporary pointer to the Linked List
	for(int i = 0; i < index; i++)					// Traverses the Linked List until its at the 
	{												// required index that has the desired path
		temp = temp->next;
	}
	cout << "Path Number: " << index << endl;		// Prints what path was chosen
	cout << "Path Distance: " << temp << endl;		// Prints the distance of this path
	cout << "Path directions from 2 to 3" << endl;	
	cout << "Start: 2" << endl;		
	for(int j = 0; j < Link2U->arrEnd; j++)			// Traverses the Array conencted to the LL
	{												// Gets each directional character: N, S, E, W
		cout << temp->Link2U->arrQ[j] << endl;		// and prints them in the apporpriate order
	}
	cout << "End: 3" << endl;

	char matS[18][16];								// Defines a character 2D array to copy the node 2D array
	for(int i = 0; i < 16; i++)						// Goes through the node 2D array and checks what 'type',
	{												// 0:empty space, 1:wall, 2:start, 3:end; each node is.
		for(int j = 0; j < 18; j++)					// It then copies the character version of each node
		{											// into the new 2D character array
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
		}
	}
	for(int i = 0; i < Link2U->arrEnd; i++)			// Traverses the array again in order to get the 
	{												// coordinates of each node on the path
		int o = temp->xCrumb[j];					// Then replacces each 0 in that specific path with
		int n = temp->yCrumb[j];					// a '*'
		matS[n][o] = '*';
	}
	cout << "Map of Chosen Path" << endl << endl;	// Prints the new 2D array with the path that was found
	for(int i = 0; i < 16; i++)
	{
		for(int j = 0; j < 18; j++)
		{
			cout << matS[j][i];
		}
		cout << endl;
	}
}

void PathFinder::SavePath(ifstream& inFile, int index)
{

}
