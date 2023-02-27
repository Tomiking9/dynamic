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

bool Freighbor::hasFree() {
    return total_free > 0;
}

int Freighbor::getFree() {
    int ret_node_index = -1;
    int counter_length = (int) sizeof(counter) / sizeof(counter[0]);
    int current_free_length = (int) sizeof(current_free) / sizeof(current_free[0]);

    for (int i = 0; i < counter_length; i++) {
        if (counter[i] > 0) {
            for (int j = i * counter_length; j < current_free_length; j++) {
                if (current_free[j] > 0) {
                    ret_node_index = j;
                    break;
                }
            }
        }

        if (ret_node_index != -1) { break; }
    }

    return ret_node_index;
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