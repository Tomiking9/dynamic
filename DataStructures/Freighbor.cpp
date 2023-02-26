#include "Freighbor.h"

Freighbor::Freighbor(bool* current, int* counter, int total){
    this->current_free = current;
    this->counter = counter;
    this->total_free = total;
}

void Freighbor::updateCurrentFree(int idx, int val) {
    this->current_free[idx] = val;
}

void Freighbor::updateCounter(int idx, bool is_edge_addition) {
    if (is_edge_addition) {
        this->counter[idx]++;
    } else {
        this->counter[idx]--;
    }
}

void Freighbor::updateTotalFree() {
    this->total_free = std::accumulate(counter, counter + ((int) sizeof(counter)/sizeof(counter[0])), 0);
}


/* Getter-Setter start */
const bool* Freighbor::getCurrentFree() const {
    return current_free;
}
void Freighbor::setCurrentFree(bool* current) {
    this->current_free = current;
}
int *Freighbor::getCounter() const {
    return counter;
}
void Freighbor::setCounter(int *counter) {
    this->counter = counter;
}
int Freighbor::getTotalFree() const {
    return total_free;
}
void Freighbor::setTotalFree(int totalFree) {
    this->total_free = totalFree;
}
/* Getter-Setter end */