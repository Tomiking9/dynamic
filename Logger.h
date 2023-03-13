#pragma once
#include "Matching.h"
#include "iostream"
#include "string"

class Logger {
    Graph* graph;

public:
    Logger(Graph*);
    void printGraphEdges();
    void printGraphNodes();
    void printGraphMatching();
};

