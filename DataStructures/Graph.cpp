#include <algorithm>
#include <iostream>
#include <numeric>
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


void Graph::setNodeFreighbors(Node* node) {
    auto nodes = sortNodes();
    auto current_neighbors = node->getNeighbors();

    // Set value to 1 if free (not in matching) and if neighbor (TODO matching)
    bool* free_neighbors = new bool[max_nodes];
    int i = 0;
    for (auto nd : nodes){
        if ((current_neighbors.find(nd) != current_neighbors.end())){
            free_neighbors[i] = true;
        }
        i++;
    }

    // Count free neighbors in chunks for faster lookup later (TODO can we do it nicer)
    int* counter = new int[(int) sqrt(max_nodes)];
    int interval = (int)sqrt(max_nodes);
    for (int j = 0; j < interval; j++) {
        for (int k = j*interval; k < (j+1)*interval; k++){
            counter[j] += free_neighbors[k];
        }
    }

    // Total amount of free neighbors of the node
    int total_free = std::accumulate(counter, counter + (sizeof(counter)/sizeof(counter[0])), 0);

    Freighbor* fr = new Freighbor(free_neighbors, counter, total_free);
    node->setFreighbor(fr);
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
