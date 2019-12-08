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
	int dist;
	int* xCrumb;
	int* yCrumb;
	struct LLPath* next;
};

struct Path
{
	int type;
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
		~PathFinder();
		Path** ConstructGraph(ifstream& inFile);
		void SearchPaths();
		void DisplayLL();
		void DisplayPath(int index);
		void SavePath(ifstream& inFile, int index);

	private:
		Path *root = NULL;
		LLPath *head = NULL;
};
