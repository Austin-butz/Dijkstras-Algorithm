#include <queue>
#include <string>

struct GraphNode {
	char key;
	int data; // Not necessary / used for Dijkstra algorithm
};


struct GraphEdge {
	GraphNode *from;
	GraphNode *to;	
	unsigned int weight;
};

struct DNode {
	int pri = INT_MAX;
	bool visited = false;
	const GraphNode *node = nullptr;
	
	bool operator<(const DNode &other) const {
		return pri < other.pri;
	}

	bool operator>(const DNode &other) const {
		return pri > other.pri;
	}
	
	bool operator==(const DNode &other) const {
		return node == other.node;
	}
};

class BetterPriorityQueue: public priority_queue<DNode, vector<DNode>, greater<DNode>>::priority_queue {
	public:
		void update();
		bool contains(GraphNode *input);
		BetterPriorityQueue();
};


class Graph{
	
	public:
		~Graph();
	
		GraphNode *AddNode(char key, int data = 0);
		GraphEdge *AddEdge(GraphNode *gn1, GraphNode *gn2, unsigned int weight = 0);
		
		string NodesToString() const;
		string ToString() const;

		static string GraphNodeToString(const GraphNode *gn);
		static string GraphEdgeToString(const GraphEdge *ge);
		
		
		const vector<GraphEdge*>& GetEdges(const GraphNode *gn) const;
		const vector<GraphNode*>& GetNodes() const;
		const GraphNode* NodeAt(unsigned int idx) const {GraphNode* temp = &nodes[idx]; return temp;}
		size_t Size() const {size_t output = nodes.size(); return output;}

	private:
		BetterPriorityQueue<DNode> nodes(26);
		BetterPriorityQueue<vector<GraphEdge>> edges(26, 26);

};
