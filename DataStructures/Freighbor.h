#pragma once
#include <cmath>
#include <array>

class Freighbor {
    std::array<bool, 10> current_free;


private:
    int* counter;
    int total_free;

public:
    Freighbor();
    void setCurrentFree(std::array<bool, 10> current);
    const std::array<bool, 10> &getCurrentFree() const;
};

