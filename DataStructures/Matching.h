#pragma once
#include <map>
#include "Node.h"

class Matching {
private:
    std::map<Node*, Node*> matching;

public:
    Node* mate(Node* node);
};

