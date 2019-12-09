#include <iostream>
#include <queue>
using namespace std;

struct PathQ
{
	char arrQ[50];
	int arrEnd;
};

struct LLPath
{
	PathQ Link2U;
	int dist=0;
	int xCrumb[50];
	int yCrumb[50];
	struct LLPath* next;
};

struct Path
{
	int type = 0;
	int x = 0;
	int y = 0;
	Path *NChild = NULL;
	Path *SChild = NULL;
	Path *WChild = NULL;
	Path *EChild = NULL;
};

class PathFinder
{
	public:
		PathFinder();
		void ConstructGraph(ifstream& inFile, Path* mat[18][16]);
		void SearchPaths(Path* root);
		void DisplayLL();
		void DisplayPath(int index, Path* mat[18][16]);
		void CreateLLNode(char arrQ[], int xCrumb[], int yCrumb[], int dist);
		void searchHelper(Path* node, char Que[], int xCrumb[], int yCrumb[], int dist, char StepDir);
	private:
		Path *root;
		LLPath *head;


};
