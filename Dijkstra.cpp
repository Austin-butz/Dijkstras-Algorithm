#include "Graph.h"
#include "BetterPriorityQueue.h"
#include <iostream>
#include <climits>
#include <cassert>

using namespace std;

//the time complexity of this algorithm mostly comes from its need to update/calculate priority and delete items from the queue. 
//For updating the items, the time complexity of doing this for a sorted list like our queue is O(log(# of nodes)).
//This needs to be done once per edge so the time complexity of updating is O((# of edges) log(# of nodes)).
//For deleting an item, the time complexity is also O(log(# of nodes)) but this is only done per node, not per edge.
//So the time complexity of deletion is is O((# of nodes) log(# of nodes)).
//combining these we get a final time complexity of O(((# of edges)+(# of nodes)) log(# of nodes))

int dijkstra(const GraphNode *start, const GraphNode *end, Graph *g){
	BetterPriorityQueue q;
	for (int i = 0; i < g->Size(); i++) {
		DNode temp;
		temp.node = g->NodeAt(i);
		if (g->NodeAt(i)->key == start->key) temp.pri = 0;
		q.push(temp);
	}
	int b = 0;
	while (q.size() > 0 && q.top().node->key != end->key) {
		cout << '(' << q.top().node->key << ": " << q.top().pri << ')' << endl; 
		b += 1;
		vector<GraphEdge*> temp = g->GetEdges(q.top().node);
		for (size_t i = 0; i < temp.size(); i++) {
			DNode temp2; 
			temp2.node = temp[i]->to;
			temp2.pri = q.top().pri + temp[i]->weight;
			q.Update(temp2);

		}
		q.pop();
	}
	return q.top().pri;
}


int DijkstraTest(){
	// Note, when grading I will replace this with
	// other / more tests.  I recommend you do the same!
	
	Graph *g = new Graph();
	
	GraphNode *a = g->AddNode('1');
	GraphNode *b = g->AddNode('2');
	GraphNode *c = g->AddNode('3');
	GraphNode *d = g->AddNode('4');
	GraphNode *e = g->AddNode('5');
	GraphNode *f = g->AddNode('6');
	
	g->AddEdge(a, b, 7);
	g->AddEdge(b, a, 7);
	g->AddEdge(a, c, 9);
	g->AddEdge(c, a, 9);
	g->AddEdge(a, f, 14);
	g->AddEdge(f, a, 14);
	
	g->AddEdge(b, c, 10);
	g->AddEdge(c, b, 10);
	g->AddEdge(b, d, 15);
	g->AddEdge(d, b, 15);
	
	g->AddEdge(c, f, 2);
	g->AddEdge(f, c, 2);
	g->AddEdge(c, d, 11);
	g->AddEdge(d, c, 11);
	
	g->AddEdge(f, e, 9);
	g->AddEdge(e, f, 9);
	
	g->AddEdge(d, e, 6);
	g->AddEdge(e, d, 6);
	
	
	cout << g->ToString() << endl;
	
	unsigned int ans = dijkstra(g->NodeAt(0), e, g);
	assert(ans == 20);

	delete g;
		
	return ans;
}


int main(){
	
	int ans = DijkstraTest();
	cout << "ans: "  << ans << endl;
	
	return 0;
}
