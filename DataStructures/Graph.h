#pragma once
#include "Node.h"
#include "Matching.h"
#include <vector>
using namespace std;

// Compare nodes based on their key data
struct NodeComparator {
    bool operator()(Node* n1, Node* n2) {
        return n1->getData() < n2->getData();
    }
    bool operator()(Node* n1, Node* n2) const {
        return n1->getData() < n2->getData();
    }
};


class Graph {
public:
    Graph(int);

    int max_nodes;
    map<Node*, set<Node*>, NodeComparator> edges;
    vector<Node*> nodes;


    void addNode(Node* node);
    void addEdge(Node *src, Node *dst);


    vector<Node*> getNodes();
    string printGraph();

    void setNodeNeighbors(Node* node);
    void setNodeFreighbor(Node* node);

    int getNodeIndex(Node *node);
};


