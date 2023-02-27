#pragma once
#include <map>
#include <set>
#include <utility>
#include "Freighbor.h"

using namespace std;

class Node {
    int data;
    int degree;
    set<Node*> neighbor;
    Freighbor* freighbor;


public:
    explicit Node(int data);

    int getData();
    int getData() const;

    set<Node*> getNeighbors();
    void setNeighbors(set<Node*> nodes);

    Freighbor* getFreighbor() const;
    void setFreighbor(Freighbor *freighbor);
};

