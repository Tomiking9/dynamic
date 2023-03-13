#include "Matching.h"

Matching::Matching(Graph *graph) {
    this->graph = graph;
}

void Matching::handleAddOneFree(Node* n1, Node* n2) {
    // n1 is free, n2 is in the matching
    auto n2_mate = n2->getMate();

    // Remove free node (n1) from n2 mate's free neighbor list (temporary)
    n2_mate->getFreighbor()->updateCurrentFree(graph->getNodeIndex(n1), 0);

    // There may be an augmenting path which contains n1---n2
    if (n2_mate->getFreighbor()->hasFree()) {
        match(n1, n2);
        match(n2_mate, graph->nodes[n2_mate->getFreighbor()->getFree()]);

        // TODO this might be wrong cz we just added smt like that
        graph->matching.erase(n2);
        graph->matching.erase(n2_mate);

    } else {
        // If we cant find a free neighbor, then n1 will remain free, and added to its neighbors free neighbor list
        for (auto n1_neighbor : n1->getNeighbors()) {
            n1_neighbor->getFreighbor()->updateCurrentFree(graph->getNodeIndex(n1), 1);
        }
    }

}

void Matching::handleAddition(Node* src, Node* dst) {
    // Updates both nodes' neighbors, degrees
    graph->addEdge(src, dst);

    // If both free, (both is true in the others free neighbor vect) match (TODO find it from the matching)
    if (dst->getFreighbor()->isFreeAtIndex(graph->getNodeIndex(src))
        && src->getFreighbor()->isFreeAtIndex(graph->getNodeIndex(dst))) {
        match(src, dst);
        // TODO ?? remove them from the free neighbor lists
    }
    // src free, dst not
    else if (dst->getFreighbor()->isFreeAtIndex(graph->getNodeIndex(src))) {
        handleAddOneFree(src, dst);
    }
    // dst free, src not
    else if (src->getFreighbor()->isFreeAtIndex(graph->getNodeIndex(dst))) {
        handleAddOneFree(dst, src);
    }
    // it shouldnt come here
    else {
        cout << "please dont";
    }
}

void Matching::handleDeletion(Node *src, Node *dst) {

}

void Matching::matchHelper(Node* node) {
    for (auto neighbor : node->getNeighbors()) {
        neighbor->getFreighbor()->updateCurrentFree(graph->getNodeIndex(node), 0);
    }
}

void Matching::match(Node *src, Node *dst) {
    // Add to matching
    graph->matching[src] = dst;

    // Remove itself from neighbors' free neighbors list, because he is no longer free
    if (src->getMate() == nullptr) {
        matchHelper(src);
    }
    if (dst->getMate() == nullptr) {
        matchHelper(dst);
    }

    src->setMate(dst);
    dst->setMate(src);
}

// TODO figure out how this works
void Matching::augmentingPath(Node *node) {
    Node* free_vertex = nullptr;

    for (auto neighbor : node->getNeighbors()) {
        auto neighbor_mate = neighbor->getMate();
        free_vertex = nullptr;

        // Find a free vertex
        if (neighbor_mate->getFreighbor()->hasFree()) {
            free_vertex = graph->nodes[neighbor_mate->getFreighbor()->getFree()];
        }

        // If found
        if (free_vertex != nullptr) {
            match(node, neighbor);
            match(neighbor_mate, free_vertex);
            graph->matching.erase(neighbor);
            graph->matching.erase(neighbor_mate);
        }
    }

    // If no augmenting path found, add the node to the neighbors free neighbor list
    for (auto neighbor : node->getNeighbors()) {
        neighbor->getFreighbor()->updateCurrentFree(graph->getNodeIndex(node), 1);
    }
    // Add it to free verticies, remove its mate
    graph->free_max.insert(node);
    node->setMate(nullptr);
}

Node* Matching::surrogate(Node *node) {
    //
    Node* surr = nullptr;
    for (auto neighbor : node->getNeighbors()) {
        surr = neighbor->getMate();

        // sqrt(number of edges)
        if (surr->getDegree() <= sqrt(100)) { continue; }

        graph->matching.erase(neighbor);
        graph->matching.erase(surr);

        match(node, neighbor);
    }
    return surr;
}



