#pragma once
#include "Node.h"
#include "Matching.h"
#include <vector>
using namespace std;

class Graph {
public:
    int max_nodes = 4;
    map<Node*, set<Node*>> edges;

    void addNode(Node* node);
    void addEdge(Node *src, Node *dst);
    void addEdge(Node* src, const set<Node*>& dst);

    vector<Node*> getNodes();
    vector<Node*> sortNodes();
    string printGraph();

    void setNodeNeighbors(Node* node);
    void setNodeFreighbors(Node* node);
};


