#pragma once
#include <cmath>
#include <array>
using namespace std;

class Freighbor {
private:
    bool* current_free;
    int* counter;
    int total_free;

public:
    Freighbor() = default;
    Freighbor(bool*, int*, int);


    int getTotalFree() const;
    void setTotalFree(int totalFree);
    int* getCounter() const;
    void setCounter(int* counter);
    void setCurrentFree(bool* current);
    const bool* getCurrentFree() const;
};

