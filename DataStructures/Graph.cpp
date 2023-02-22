//
// Created by Számel Tamás on 2023. 02. 20..
//

#include <algorithm>
#include "Graph.h"


Node** Graph::getNodes() {
    auto nodes = new Node*[10];
    int i = 0;
    for (const auto &[key, val] : edges){
         nodes[i] = key;
         i++;
    }
    return nodes;
}

Node** Graph::sortNodes() {
    Node** sorted = new Node*[10];
    auto nodes = getNodes();

    std::sort(nodes, nodes + sizeof(nodes) / sizeof(nodes[0]));
    return sorted;
}

int Graph::print(){return 1;}