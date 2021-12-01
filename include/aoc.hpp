#pragma once

#include <iostream>
#include <vector>

template <typename T> void read_input(std::vector<T> &container) {
    T in;
    for (std::cin >> in; !std::cin.eof(); std::cin >> in) {
        container.push_back(in);
    }
}