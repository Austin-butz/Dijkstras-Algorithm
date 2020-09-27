#include <queue>
#include <string>
#include <vector>
#include <climits>
#include <iostream>
using namespace std;
#ifndef GRAPH_H
#define GRAPH_H

struct GraphNode {
	char key;
	int data; // Not necessary / used for Dijkstra algorithm
};


struct GraphEdge {
	GraphNode *from;
	GraphNode *to;	
	unsigned int weight;
};

class Graph{
	
	public:
		~Graph();
	
		GraphNode *AddNode(char key, int data = 0);
		GraphEdge *AddEdge(GraphNode *gn1, GraphNode *gn2, unsigned int weight = 0);
		
		string NodesToString() const;
		string ToString() const;

		static string GraphNodeToString(GraphNode const* gn);
		static string GraphEdgeToString(GraphEdge const* ge);
		
		
		const vector<GraphEdge*>& GetEdges(const GraphNode *gn) const;
		const vector<GraphNode*>& GetNodes() const;
		const GraphNode* NodeAt(unsigned int idx) const {return &nodes[idx];}
		size_t Size() const {return nodes.size();}

	private:
		vector<GraphNode> nodes;
		vector<vector<GraphEdge*>> edges;

};
#endif