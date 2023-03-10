#pragma once
#include "DataStructures/Graph.h"

class Matching {
    Graph* graph;

    explicit Matching(Graph*);

    void handleAddition(Node*, Node*);
    void handleDeletion(Node*, Node*);
    void match(Node*, Node*);
    void augmentingPath(Node*);
    Node* surrogate(Node*);
};

