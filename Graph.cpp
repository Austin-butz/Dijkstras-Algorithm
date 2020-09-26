#include "Graph.h"

Graph::~Graph() {
    cout << ' ';
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
    cout << "start addedge" << endl;
    size_t i = NULL;
    size_t b;
    bool found = false;
    if (edges.size() == 0) i = 0;
    else {
        for (b = 0; b < edges.size(); b++) {
            if (edges[b][0]->from->key == gn1->key) {
                //cout << edges[b][0]->from->key << " == " << gn1->key << endl;
                found = true;
                break;
            }
        }
        //cout << "i found: " << b << endl << edges[b][0]->from->key << ' ' << gn1->key << endl;
    }
    if (found == true) {
        //cout << "true" << endl;
        i = b;
    }
    else if (found == false || i == 0) {
        //cout << "new " << found << ' ' << i << endl;
        vector<GraphEdge*> *temp1 = new vector<GraphEdge*>;
        edges.push_back(*temp1);
        if (i != 0) i = edges.size();
    }
    GraphEdge* temp = new GraphEdge;
    //cout << "imp " << gn1->key << endl;
    temp->from = gn1;
    temp->to = gn2;
    temp->weight = weight;
    edges[i].push_back(temp);
    //cout << i << ' ' << GraphEdgeToString(edges[i].back()) << endl;
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
    //cout << nodes.size() << endl;
    for (size_t i = 0; i < nodes.size(); i++) { 
        //cout << "start loop ";
        string temp(1, nodes[i].key);
        cout << "temp: " << temp << endl; // just checking what this variable is
        output.insert(output.size(), temp);
        output.insert(output.size(), " | ");
        if (edges.size() > i) {
            //cout << "edge size: " << edges.size() << " > i: " << i << endl;
            //vector<GraphEdge*> temp;
            //edges.push_back(temp);
            //cout << edges[i][0]->from->key;
            cout << "vector: " << vec_to_string(edges[i]) << endl;
            if ( (edges[i].size() != 0) && (edges[i][0]->from->key == nodes[i].key)) {
                //cout << "i: " << i << " | " << edges[i][0]->from->key << nodes[i].key << endl;
                output.insert(output.size(), GraphEdgeToString(edges[i][0]));
                if (edges[i].size() > 1) {
                    for (size_t j = 1; j < edges[i].size(); j++) {
                        output.insert(output.size(), ", ");
                        output.insert(output.size(), GraphEdgeToString(edges[i][j]));
                    }
                }
            }
        }
        output.insert(output.size(), "\n");
        cout << "graph so far: " << output << endl;
    }
    //cout << output;
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
    vector<GraphEdge*> output;
    vector<string> apl = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
    size_t i;
    for (i = 0; i < apl.size(); i++) {
        if (apl[i] == to_string(gn->key)) break;
    }
    for (size_t j = 0; j < edges[i].size(); j++) {
        GraphEdge* temp = edges[i][j];
        output.push_back(temp);
    }
    return edges[i];
}

const vector<GraphNode*>& Graph::GetNodes() const {
    // why not just return the node vector (defined in Graph.h)
    // private: vector<GraphNode> nodes;
    vector<GraphNode*> output;
    for (size_t i = 0; i < nodes.size(); i++) {
        GraphNode* temp = new GraphNode;
        temp->key = nodes[i].key;
        output.push_back(temp);
    }
    return output;
}

void BetterPriorityQueue::Update() {
    cout << ' ';
};

int BetterPriorityQueue::Contains(DNode input) {
    for (size_t i = 0; i < this->size(); i++) {
        if (c[i].node->key == input.node->key) {
            return i;
        }
    }
    cout << "No node with given key in queue" << endl;
    return NULL;
};