#pragma once
#include <cmath>
#include <array>
#include <numeric>
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
    void setTotalFree(int);
    int* getCounter() const;
    void setCounter(int*);
    void setCurrentFree(bool*);
    const bool* getCurrentFree() const;

    void updateCurrentFree(int, int);
    void updateCounter(int, bool);
    void updateTotalFree();
    bool hasFree();
    bool isFreeAtIndex(int);
    int getFree();
};

