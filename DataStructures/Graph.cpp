#include <algorithm>
#include <iostream>
#include "Graph.h"


vector<Node*> Graph::getNodes() {
    auto nodes = new vector<Node*>;
    for (const auto &[key, val] : edges){
         nodes->push_back(key);
    }
    return *nodes;
}

bool compareNodes(Node* n1, Node* n2) {return n1->getData() < n2->getData();}
vector<Node*> Graph::sortNodes() {
    auto sorted = getNodes();
    std::sort(sorted.begin(),sorted.end(), compareNodes);
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
