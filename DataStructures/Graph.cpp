#include "Graph.h"


Graph::Graph(int nodes) {
    this->max_nodes = nodes;
    this->nodes = *new std::vector<Node*>();
    this->edges = *new map<Node*, set<Node*>, NodeComparator>();
}

vector<Node*> Graph::getNodes() {
    auto nodes_vect = new vector<Node*>;
    for (const auto &[key, val] : edges){
         nodes_vect->push_back(key);
    }
    return *nodes_vect;
}

int Graph::getNodeIndex(Node* node) {
    auto it = find(nodes.begin(), nodes.end(), node);
    if (it != nodes.end()) {
        return it - nodes.begin();
    }

    // If node not in graph
    return -1;
}

void Graph::addNode(Node *node) {
    // Node in graph
    this->edges[node] = {};

    // Node locally
    setNodeNeighbors(node);
    setNodeFreighbor(node);
}


void Graph::addEdge(Node *src, Node* dst) {
    // Node not in graph
    if (edges.find(src) == edges.end()) {
        edges[src] = {dst};

    // Already in graph
    } else {
        edges[src].insert(dst);
    }

    // Update node neighbors with the new edge
    setNodeNeighbors(src);

    // Update node freighbors if the destination node is not in the matching
    int nodeIndex = getNodeIndex(dst);
    if (matching.find(dst) == matching.end()) {
        src->getFreighbor()->updateCurrentFree(nodeIndex, 1);
        src->getFreighbor()->updateCounter( (int)nodeIndex / sqrt(max_nodes), true);
        src->getFreighbor()->updateTotalFree();
    }

}

void Graph::setNodeNeighbors(Node* node){
    node->setNeighbors(edges[node]);
}

void Graph::setNodeFreighbor(Node* node) {
    auto current_neighbors = node->getNeighbors();

    // Set value to 1 if free (not in matching) and if neighbor
    bool* free_neighbors = new bool[max_nodes];
    int i = 0;
    for (auto nd : nodes){
        if (
                // Edge is present in the original graph (so its a neighbor)
                (current_neighbors.find(nd) != current_neighbors.end())
                &&
                // Node not in the matching (so its free)
                matching.find(nd) == matching.end())

        {
            free_neighbors[i] = true;
        }
        i++;
    }

    // Count free neighbors in chunks for faster lookup later (TODO can we do it nicer)
    int* counter = new int[(int) sqrt(max_nodes)];
    int interval = (int)sqrt(max_nodes);
    for (int j = 0; j < interval; j++) {
        for (int k = j*interval; k < (j+1)*interval; k++){
            counter[j] += free_neighbors[k];
        }
    }

    // Total amount of free neighbors of the node
    int total_free = std::accumulate(counter, counter + ((int) sizeof(counter)/sizeof(counter[0])), 0);

    Freighbor* fr = new Freighbor(free_neighbors, counter, total_free);
    node->setFreighbor(fr);
}

string Graph::printGraph() {
    string ret;
    for (const auto &[key, val] : edges){
        ret += std::to_string(key->getData()) += " --> ";
        for (Node* node : val){
            ret += std::to_string(node->getData()) += ", ";
        }
        ret += "\n";
    }
    return ret;
}
