#include <queue>

class BetterPriorityQueue: public priority_queue<DNode, vector<DNode>, greater<DNode>>::priority_queue {
	public:
		void update();
		bool contains(GraphNode *input);
};