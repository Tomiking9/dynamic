#pragma once
#include "Node.h"

using namespace std;

class Graph {
public:
    int max_nodes;
    map<Node*, set<Node*>> edges;

    void addNode(Node* node);
    void addEdge(Node *src, Node *dst);
    void addEdge(Node* src, const set<Node*>& dst);
    Node** getNodes();
    Node** sortNodes();
    string printGraph();

};


