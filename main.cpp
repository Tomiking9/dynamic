#include "DataStructures/Graph.h"
#include <iostream>


int main(int argc, const char * argv[]) {
    Graph* g = new Graph();
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    g->addNode(n1);
    g->addNode(n2);
    g->addNode(n3);

    g->addEdge(n1, n2);
    g->addEdge(n1, n3);

    cout << g->printGraph();
    return 0;
}