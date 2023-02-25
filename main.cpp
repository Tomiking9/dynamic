#include "DataStructures/Graph.h"
#include <iostream>
#include <iterator>

int main(int argc, const char* argv[]) {
    auto* g = new Graph();

    Node* n1 = new Node(1);
    Node* n2 = new Node(24);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    g->addNode(n2);
    g->addNode(n1);
    g->addNode(n3);
    g->addNode(n4);

    g->addEdge(n1, n2);
    g->addEdge(n1, n4);

    g->setNodeNeighbors(n1);
    g->setNodeFreighbors(n1);

    for (auto node : n1->getFreighbor()->getCurrentFree()){
        cout << node << endl;
    }

    return 0;
}