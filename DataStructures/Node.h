#pragma once

#include <map>
#include <set>
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

};

