#include "Freighbor.h"

Freighbor::Freighbor(bool* current, int* counter, int total){
    this->current_free = current;
    this->counter = counter;
    this->total_free = total;
}

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
