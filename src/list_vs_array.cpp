#include <cstddef>  // size_t
#include <iostream>
#include <list>
#include <random>

#include "timer.h"

constexpr size_t SIZE = 16000000;

int main() {
    // test here...
    Timer timer;
    std::list<uint64_t> list;
    std::vector<uint64_t> vector;
    std::vector<uint64_t> vector_reserved;
    std::mt19937_64 rng(0);
    uint64_t summed_value = 0;
    uint64_t next;

    rng.seed(0);
    timer.restart();
    for (size_t i = 0; i < SIZE; ++i) {
        next = rng();
        list.push_back(next);
    }
    std::cout << "List: " << timer.glance<Timer::microseconds>() << std::endl;

    rng.seed(0);
    timer.restart();
    for (size_t i = 0; i < SIZE; ++i) {
        next = rng();
        vector.push_back(next);
    }
    std::cout << "Normal Vector: " << timer.glance<Timer::microseconds>() << std::endl;

    vector_reserved.reserve(SIZE);
    rng.seed(0);
    timer.restart();
    for (size_t i = 0; i < SIZE; ++i) {
        next = rng();
        vector_reserved.push_back(next);
    }
    std::cout << "Reserved Vector: " << timer.glance<Timer::microseconds>() << std::endl;

    timer.restart();
    for (auto items : list) {
        summed_value += items;
    }
    std::cout << "Summed Value List: " << summed_value << " In " << timer.glance<Timer::microseconds>() << " Microseconds" << std::endl;

    summed_value = 0;
    timer.restart();
    for (auto items : vector) {
        summed_value += items;
    }
    std::cout << "Summed Value Vector: " << summed_value << " In " << timer.glance<Timer::microseconds>() << " Microseconds" << std::endl;

    summed_value = 0;
    timer.restart();
    for (auto items : vector_reserved) {
        summed_value += items;
    }
    std::cout << "Summed Value Reserved Vector: " << summed_value << " In " << timer.glance<Timer::microseconds>() << " Microseconds" << std::endl;
    return 0;
}
