#include <algorithm>
#include <iostream>
#include <array>
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


void Graph::setNodeNeighbors(Node* node){
    node->setNeighbors(edges[node]);
}


void Graph::setNodeFreighbors(Node* node){
    auto nodes = sortNodes();
    auto current_neighbors = node->getNeighbors();
    std::array<bool, 10> free_neighbors{};

    std::fill(begin(free_neighbors), end(free_neighbors), false);

    int i = 0;
    for (auto nd : nodes){
        if ((current_neighbors.find(nd) != current_neighbors.end())){
            free_neighbors[i] = true;
        }
        i++;
    }
    node->getFreighbor()->setCurrentFree(free_neighbors);
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
