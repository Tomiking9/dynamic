//
// Created by Számel Tamás on 2023. 02. 20..
//

#ifndef DYNAMIC_NODE_H
#define DYNAMIC_NODE_H

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

public:
    int getData();
    int print();
};

bool operator<(Node n1, Node n2){
    return n1.getData() < n2.getData();
}
bool operator==(Node n1, Node n2){
    return n1.getData() == n2.getData();
}


#endif //DYNAMIC_NODE_H
