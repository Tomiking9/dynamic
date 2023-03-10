//
// Created by Számel Tamás on 2023. 03. 10..
//

#include "Matching.h"

Matching::Matching(Graph *graph) {
    this->graph = graph;
}

void Matching::handleAddition(Node* src, Node* dst) {
    graph->addEdge(src, dst);

    // If both free (both is true in the others free neighbor vect) match
    if (dst->getFreighbor()->getCurrentFree()[graph->getNodeIndex(src)] &&
        src->getFreighbor()->getCurrentFree()[graph->getNodeIndex(dst)]){
        match(src, dst);
    }

    // TODO other way, different func, cleaner
    else if (dst->getFreighbor()->getCurrentFree()[graph->getNodeIndex(src)]) {
        auto dst_dash = dst->getMate();

        // Remove free node (src) from dst mate's free neighbor list
        dst_dash->getFreighbor()->updateCurrentFree(graph->getNodeIndex(src), 0);

        if (dst_dash->getFreighbor()->hasFree()) {
            match(src, dst); // TODO why are we matching these again ffs
            match(dst_dash, graph->nodes[dst_dash->getFreighbor()->getFree()]);
            graph->matching.erase(dst);
            graph->matching.erase(dst_dash);
        } else {
            for (auto src_neigh : src->getNeighbors()) {
                src_neigh->getFreighbor()->updateCurrentFree(graph->getNodeIndex(src), 1);
            }
        }
    }

}

void Matching::handleDeletion(Node *src, Node *dst) {

}

void Matching::match(Node *src, Node *dst) {
    graph->matching[src] = dst;

    // TODO other way, different func
    // Remove itself from neighbors' free neighbors list
    if (src->getMate() == nullptr) {
        for (auto nd : src->getNeighbors()) {
            nd->getFreighbor()->updateCurrentFree(graph->getNodeIndex(src), 0);
        }
    }

    // why this
    src->setMate(dst);
    dst->setMate(src);
}

// TODO figure out how this works
void Matching::augmentingPath(Node *node) {
    Node* free_vertex = nullptr;

    for (auto nd : node->getNeighbors()) {
        auto nd_dash = nd->getMate();
        free_vertex = nullptr;

        // If free vertex found
        if (nd_dash->getFreighbor()->hasFree()) {
            free_vertex = graph->nodes[nd_dash->getFreighbor()->getFree()];
        }

        if (free_vertex != nullptr) {
            match(node, nd);
            match(nd_dash, free_vertex);
            graph->matching.erase(nd);
            graph->matching.erase(nd_dash);
        }
    }
    // If no augmenting path found
    for (auto nd : node->getNeighbors()) {
        nd->getFreighbor()->updateCurrentFree(graph->getNodeIndex(node), 0);
    }
    graph->free_max.insert(node);
    node->setMate(nullptr);
}

// TODO figure out what this is
Node* Matching::surrogate(Node *node) {
    Node* surr = nullptr;
    for (auto nd : node->getNeighbors()) {
        surr = nd->getMate();
        // sqrt(number of edges)
        if (surr->getDegree() <= sqrt(100)) { continue; }

        graph->matching.erase(nd);
        graph->matching.erase(surr);

        match(node, nd);
    }
    return surr;
}



