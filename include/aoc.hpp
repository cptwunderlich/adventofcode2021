#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

namespace aoc {

std::vector<std::string> split(std::string s, char delim = ' ') {
    std::vector<std::string> res;
    std::string::const_iterator last = s.cbegin();
    std::string::const_iterator it = s.cbegin();

    do {
        it = std::find(it, s.cend(), delim);
        if (it != last) res.push_back(std::string(last, it));
        if (it != s.cend()) it++;
        last = it;
    } while (it != s.cend());

    return res;
}

template <typename T> void read_input(std::vector<T> &container) {
    T in;
    for (std::cin >> in; !std::cin.eof(); std::cin >> in) {
        container.push_back(in);
    }
}

}