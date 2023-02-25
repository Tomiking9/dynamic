#include <algorithm>
#include <iostream>
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

void Graph::addNode(Node *node) {
    this->edges[node] = {};
}

void Graph::addEdge(Node *src, const set<Node*>& dst) {
    if (edges.find(src) == edges.end()) {
        edges[src] = dst;
    } else {
        edges[src].insert(dst.begin(), dst.end());
    }
}

void Graph::addEdge(Node *src, Node* dst) {
    if (edges.find(src) == edges.end()) {
        edges[src] = {dst};
    } else {
        edges[src].insert(dst);
    }
}


string Graph::printGraph() {
    string ret;
    for (const auto &[key, val] : edges){
        ret += std::to_string(key->getData()) += " --> ";
        for (Node* node : val){
            ret += std::to_string(node->getData()) += ", ";
        }
        ret += "\n";
    }
    return ret;
}
