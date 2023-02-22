//
// Created by Számel Tamás on 2023. 02. 20..
//

#ifndef DYNAMIC_GRAPH_H
#define DYNAMIC_GRAPH_H


#include "Node.h"

using namespace std;

class Graph {
public:
    int max_nodes;
    map<Node*, set<Node*>> edges;

    Node** getNodes();
    Node** sortNodes();
    int print();
};


#endif //DYNAMIC_GRAPH_H
