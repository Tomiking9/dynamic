//
// Created by Számel Tamás on 2023. 02. 20..
//

#pragma once
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


