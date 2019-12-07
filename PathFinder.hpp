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
	struct LLPath* next;
};

struct Path
{
	int x = 0;
	int y = 0;
	Path *northChild = NULL;
	Path *southChild = NULL;
	Path *westChild = NULL;
	Path *eastChild = NULL;
};

class PathFinder
{
	public:
		path();
		~path();
		void ConstructGraph(ifstream& inFile);
		void SearchPaths();
		void DisplayLL();
		void DisplayPath(int index);
		void SavePath(ifstream& inFile, int index);

	private:
		Path *root = NULL;
		LLPath *head = NULL;
};
