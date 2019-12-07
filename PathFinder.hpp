#include <iostream>
#include <queue>
using namespace std;

struct Path
{
	int x = 0;
	int y = 0;
	Path *NPC = NULL;	
	Path *northChild = NULL;
	Path *southChild = NULL;
	Path *westChild = NULL;
	Path *eastChild = NULL;
	Path *prev = NULL;
};

class PathFinder
{
	public:
		path();
		~path();


	private:
		Path *head = NULL;
};