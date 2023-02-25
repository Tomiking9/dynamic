//
// Created by Számel Tamás on 2023. 02. 20..
//

#include <numeric>
#include "Freighbor.h"


#define n 10

Freighbor::Freighbor(){
    this->current_free = std::array<bool, 10>();
    this->counter = new int[floor(sqrt(n))];
    this->total_free = std::accumulate(counter, counter+((int)sizeof(counter) / sizeof(counter[0])), 0);
}

void Freighbor::setCurrentFree(std::array<bool, 10> current) {
    this->current_free = current;
}

const std::array<bool, 10> &Freighbor::getCurrentFree() const {
    return current_free;
}
