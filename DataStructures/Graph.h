#pragma once
#include "Node.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <map>

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

// not working with this rn
struct FreeMaxComp {
    bool operator()(Node* n1, Node* n2) {
        return n1->getDegree() > n2->getDegree();
    }
    bool operator()(Node* n1, Node* n2) const {
        return n1->getDegree() > n2->getDegree();
    }
};


class Graph {
public:
    explicit Graph(int);

    int max_nodes;
    vector<Node*> nodes;
    map<Node*, set<Node*>, NodeComparator> edges;
    map<Node*, Node*, NodeComparator> matching;
    multiset<Node*, FreeMaxComp> free_max;

    void addNode(Node* node);
    void addEdge(Node *src, Node *dst);

    void setNodeNeighbors(Node* node);
    void setNodeFreighbor(Node* node);

    int getNodeIndex(Node *node);
    vector<Node*> getNodes();
    string printGraph();
};


