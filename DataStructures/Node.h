#pragma once
#include <map>
#include <set>
#include <utility>
#include "Freighbor.h"

using namespace std;

class Node {
private:
    int data;
    int degree;
    Node* mate;
public:
    Node *getMate() const;

    void setMate(Node *mate);

private:
    set<Node*> neighbor;
    Freighbor* freighbor;


public:
    explicit Node(int data);

    int getData();
    int getData() const;
    int getDegree() const;
    void setDegree(int degree);

    set<Node*> getNeighbors();
    void setNeighbors(set<Node*> nodes);

    Freighbor* getFreighbor() const;
    void setFreighbor(Freighbor *freighbor);
};

