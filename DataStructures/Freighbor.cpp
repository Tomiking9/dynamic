//
// Created by Számel Tamás on 2023. 02. 20..
//

#include <numeric>
#include "Freighbor.h"


#define n 10

Freighbor::Freighbor(){
    this->current_free = new bool[n];
    this->counter = new int[floor(sqrt(n))];
    this->total_free = std::accumulate(counter, counter+((int)sizeof(counter) / sizeof(counter[0])), 0);
}
