#include <iostream>
using namespace std;

struct Path
{
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