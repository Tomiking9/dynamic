#include "Logger.h"
#include <iostream>
#include <iterator>

int main(int argc, const char* argv[]) {
    auto* graph = new Graph(4);

    Node* n1 = new Node(1);
    Node* n2 = new Node(24);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);


    graph->addNode(n1);
    graph->addNode(n3);
    graph->addNode(n2);
    graph->addNode(n4);


    graph->addEdge(n1, n2);
    graph->addEdge(n1, n3);

    Logger* logger = new Logger(graph);
    logger->printGraphNodes();

    return 0;
}



/*
    g->setNodeFreighbor(n1);


    g->nodes = g->getNodes();
    cout << "NODES" << endl;
    for (int i = 0; i < g->max_nodes; i++) {
        cout << i << ": " << g->nodes[i]->getData() << endl;
    }


    cout << "-------" << endl;
    for (int i = 0; i < g->max_nodes; i++) {
        cout << i << ": " << n1->getFreighbor()->getCurrentFree()[i] << endl;
    }

    g->addEdge(n1, n2);
    cout << "-------" << endl;
    for (int i = 0; i < g->max_nodes; i++) {
        cout << i << ": " << n1->getFreighbor()->getCurrentFree()[i] << endl;
    }
    for (int i = 0; i < 2; i++) {
        cout << i << ": " << n1->getFreighbor()->getCounter()[i] << endl;
    }


    g->addEdge(n1, n4);
    cout << "-------" << endl;

    for (int i = 0; i < g->max_nodes; i++) {
        cout << i << ": " << n1->getFreighbor()->getCurrentFree()[i] << endl;
    }
    for (int i = 0; i < 2; i++) {
        cout << i << ": " << n1->getFreighbor()->getCounter()[i] << endl;
    }
 */