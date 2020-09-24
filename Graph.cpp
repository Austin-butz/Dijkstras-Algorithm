#include "Graph.h"
using namespace std;

GraphNode * Graph::AddNode(char key, int data = 0) {
    GraphNode temp;
    temp.key = key;
    temp.data = data;
    DNode output;
    output.node = &temp;
    this->nodes.push_back(output);
    return &temp;
};

GraphEdge * Graph::AddEdge(GraphNode *gn1, GraphNode *gn2, unsigned int weight = 0) {
    vector<char> apl = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int i = 0;
    for (i; i < apl.size(); i++) if (apl[i] == gn1->key) break;
    GraphEdge temp;
    temp.from = gn1;
    temp.to = gn2;
    temp.weight = weight;
    edges[i].push_back(temp);
    return &temp;
};

string Graph::NodesToString() const {
    string output = "[";
    int i;
    for (i  = 0; i < nodes.size()-1; i++) {
        output.insert(output.size(), GraphNodeToString(nodes[i]));
        output.insert(output.size(), ", ");
    }
    i += 1;
    output.insert(output.size(), GraphNodeToString(nodes[i]));
    output.insert(output.size(), "]");
    return output;
}

string Graph::ToString() const {
    string output;
    for (int i = 0; i < nodes.size(); i++) { 
        output.insert(output.size(), to_string(nodes[i]->node.key));
        output.insert(output.size(), " | ");
        if (edges[i][0]->from.key == nodes[i].key) {
            output.insert(output.size(), GraphEdgeToString(&edges[i][0]));
            for (int j = 1; j < nodes[i].size(); j++) {
                output.insert(output.size(), ", ");
                output.insert(output.size(), GraphEdgeToString(&edges[i][j]));
            }
        }
        output.insert(output.size(), "\n");
    }
    return output;
}

static string GraphNodeToString(const GraphNode *gn) {
    string output = "(";
    output.insert(output.size(), to_string(gn->key));
    output.insert(output.size(),":");
    output.insert(output.size(), to_string(gn->data));
    output.insert(output.size(),")");
    return output;
}

static string GraphEdgeToString(const GraphEdge *ge) {
    string output = "[";
    output.insert(output.size(), GraphNodeToString(ge->from));
    output.insert(output.size(), "->");
    output.insert(output.size(), GraphNodeToString(ge->to));
    output.insert(output.size(), " w:");
    output.insert(output.size(), to_string(ge->weight));
    output.insert(output.size(), "]");

}

const vector<GraphEdge*>& Graph::GetEdges(const GraphNode *gn) const {
    vector<GraphEdge*> output;
    vector<string> apl = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
    int i = 0;
    for (i; i < apl.size(); i++) {
        if (apl[i] == to_string(gn->key)) break;
    }
    for (int j = 0; j < edges[i].size(); j++) {
        GraphEdge* temp = &edges[i][j];
        output.push_back(temp);
    }
    return output;
}

const vector<GraphNode*>& Graph::GetNodes() const {
    vector<GraphNode*> output;
    for (int i = 0; i < nodes.size(); i++) {
        GraphNode* temp = &nodes[i];
        output.push_back(temp);
    }
    return output;
}

void BetterPriorityQueue::update() {
int i = 0;
};

bool BetterPriorityQueue::contains(GraphNode *input) {
    for (int i = 0; i < this->size(); i++) {
        if (c[i].node->key == input->key) {
            return true;
        }
    }
    return false;
};