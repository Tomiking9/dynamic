#include "Graph.h"


Graph::Graph(int nodes) {
    this->max_nodes = nodes;
    this->edges = *new map<Node*, set<Node*>, NodeComparator>();
    this->nodes = getNodes();
}

// TODO replace this
vector<Node*> Graph::getNodes() {
    auto nodes_vect = new vector<Node*>;
    for (const auto &[key, val] : edges){
         nodes_vect->push_back(key);
    }
    return *nodes_vect;
}

int Graph::getNodeIndex(Node* node) {
    return distance(edges.begin(),edges.find(node));
}

void Graph::addNode(Node *node) {
    // Node in graph
    this->edges[node] = {};

    // Node locally
    setNodeNeighbors(node);
    setNodeFreighbor(node);

    // Node into F_max
    free_max.insert(node);
}


void Graph::addEdge(Node* src, Node* dst) {
    // Node in graph
    if (edges.find(src) != edges.end()) {
        edges[src].insert(dst);
    } else {
        cout << "how did this happen";
    }

    // Update node neighbors with the new edge
    setNodeNeighbors(src);
    setNodeNeighbors(dst);

    // TODO how to remove redundant elements
    // Update the degree on both
    free_max.extract(src);
    src->setDegree(src->getDegree() + 1);
    free_max.insert(src);

    free_max.extract(dst);
    dst->setDegree(dst->getDegree() + 1);
    free_max.insert(dst);


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
    for (const auto &[key, val]: edges){
        if (
                // Edge is present in the original graph (so its a neighbor)
                (current_neighbors.find(key) != current_neighbors.end())
                &&
                // Node not in the matching (so its free)
                matching.find(key) == matching.end())

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

    auto* fr = new Freighbor(free_neighbors, counter, total_free);
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
