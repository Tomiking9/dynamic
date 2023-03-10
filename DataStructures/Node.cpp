#include "Node.h"

Node::Node(int data){
    this->data = data;
    this->degree = 0;
    this->mate = nullptr;
    this->neighbor = set<Node*>();
    this->freighbor = new Freighbor();
}


/* Getter-Setter start */
int Node::getData() {
    return this->data;
}
int Node::getData() const {
    return this->data;
}
void Node::setNeighbors(set<Node*> nodes){
    this->neighbor = std::move(nodes);
}
set<Node*> Node::getNeighbors() {
    return this->neighbor;
}
Freighbor* Node::getFreighbor() const {
    return freighbor;
}
void Node::setFreighbor(Freighbor *freighbor) {
    Node::freighbor = freighbor;
}

int Node::getDegree() const {
    return degree;
}

void Node::setDegree(int degree) {
    Node::degree = degree;
}

Node *Node::getMate() const {
    return mate;
}

void Node::setMate(Node *mate) {
    Node::mate = mate;
}
/* Getter-Setter end */