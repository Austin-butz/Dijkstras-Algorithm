#include <queue>
#include "Graph.h"
#include <iostream>
using namespace std;

class BetterPriorityQueue: public priority_queue<DNode, vector<DNode>, greater<DNode>>::priority_queue {
	public:
		void Update();
		int Contains(char key);
};
