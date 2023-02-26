#include "Node.h"

#include <utility>

Node::Node(int data){
    this->data = data;
    this->degree = 0;
    this->neighbor = set<Node*>();
    this->freighbor = new Freighbor();
}

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





/*
bool operator<(const Node& n1, const Node& n2){
    return n1.getData() < n2.getData();
}
bool operator==(const Node& n1, const Node& n2){
    return n1.getData() == n2.getData();
}
*/