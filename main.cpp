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

    auto sorted = g->sortNodes();

    auto current_free = n1->getFreighbor()->getCurrentFree();
    auto counter = n1->getFreighbor()->getCounter();


    for (int i = 0; i < g->max_nodes; i++){
        cout << sorted[i]->getData() << ": " << current_free[i] << endl;
    }

    cout << "------" << endl;
    for (int i = 0; i < (int)sqrt(g->max_nodes); i++){
        cout << counter[i] << endl;
    }
    cout << "------" << endl;
    cout << n1->getFreighbor()->getTotalFree();
    return 0;
}