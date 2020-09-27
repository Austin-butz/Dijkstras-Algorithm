#include "Graph.h"

Graph::~Graph() {
    this->nodes.clear();
    for (int i  = 0; i < edges.size(); i++) {
        edges[i].clear();
    }
    edges.clear();
}

GraphNode * Graph::AddNode(char key, int data) {
    GraphNode* temp = new GraphNode;
    GraphNode output;
    temp->key = key;
    temp->data = data;
    output = *temp;
    nodes.push_back(output);
    return temp;
};

GraphEdge * Graph::AddEdge(GraphNode *gn1, GraphNode *gn2, unsigned int weight) {
    size_t i = edges.size();
    size_t b = 0;
    bool found = false;
    if (edges.size() > 0) {
        for (b; b < edges.size(); b++) {
            if (edges[b][0]->from->key == gn1->key) {
                found = true;
                break;
            }
        }
    }
    if (found == false || i == 0) {
        vector<GraphEdge*> *temp1 = new vector<GraphEdge*>;
        edges.push_back(*temp1);
    }
    GraphEdge* temp = new GraphEdge;
    temp->from = gn1;
    temp->to = gn2;
    temp->weight = weight;
    if (found == true) {
        i = b;
    }
    edges[i].push_back(temp);
    return temp;
};

string Graph::NodesToString() const {
    string output(1, '[');
    size_t i = 0;
    do {
        output.insert(output.size(), GraphNodeToString(&nodes[i]));
        if (i != nodes.size()-1) output.insert(output.size(), ", ");
        i += 1;
    } 
    while (i <= nodes.size()-1);
    output.insert(output.size(), "]");
    return output;
}


string vec_to_string(vector<GraphEdge*> vec){

    if(vec.size() == 0){
        return "[]";
    }

    string s = "[";
    for(size_t i = 0; i < vec.size(); i++){
        s = s + Graph::GraphEdgeToString(vec.at(i));
        if( i < vec.size() - 1){
            s = s + ", ";
        }
    }
    s = s + "]";
    return s;
}

string Graph::ToString() const {
    string output;
    for (size_t i = 0; i < nodes.size(); i++) { 
        string temp;
        temp = temp + nodes[i].key;
        temp = temp + " | ";
        output.insert(output.size(), temp);
        size_t j = edges.size();
        for (size_t b = 0; b < edges.size(); b++) if (edges[b][0]->from->key == nodes[i].key) {
            j = b; 
            break;
        }
        if (j != edges.size()) {
            for (size_t e = 0; e < edges[j].size(); e++) {
                output.insert(output.size(), GraphEdgeToString(edges[j][e]));
                if (e != edges[j].size()-1) output.insert(output.size(), ", ");
            }
        }
        output.insert(output.size(), "\n");
    }
    return output;
}

string Graph::GraphNodeToString(GraphNode const* gn) {
    string output = "(";
    string temp(1, gn->key);
    output.insert(output.size(), temp);
    output.insert(output.size(),":");
    output.insert(output.size(), to_string(gn->data));
    output.insert(output.size(),")");
    return output;
}

string Graph::GraphEdgeToString(GraphEdge const* ge) {
    string output = "[";
    output.insert(output.size(), GraphNodeToString(ge->from));
    output.insert(output.size(), "->");
    output.insert(output.size(), GraphNodeToString(ge->to));
    output.insert(output.size(), " w:");
    output.insert(output.size(), to_string(ge->weight));
    output.insert(output.size(), "]");
    return output;
}

const vector<GraphEdge*>& Graph::GetEdges(const GraphNode *gn) const {
    size_t b = edges.size();
    for (size_t i = 0; i < edges.size(); i++) {
        if (edges[i][0]->from->key == gn->key) {
            b = i;
            break;
        }
    }
    if (b != edges.size()) return edges[b];
}

const vector<GraphNode*>& Graph::GetNodes() const {
    vector<GraphNode*> output;
    for (size_t i = 0; i < nodes.size(); i++) {
        GraphNode* temp = new GraphNode;
        temp->key = nodes[i].key;
        output.push_back(temp);
    }
    return output;
}