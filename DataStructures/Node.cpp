//
// Created by Számel Tamás on 2023. 02. 20..
//

#include "Node.h"

Node::Node(int data){
    this->data = data;
    this->degree = 0;
    this->neighbor = set<Node*>();
    this->freighbor = new Freighbor();
}

int Node::getData() {
    return this->data;
}

int Node::print(){
    return 1;
}