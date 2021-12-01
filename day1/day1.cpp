#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

#include "../include/aoc.hpp"

using vec_input_it = std::vector<int>::const_iterator;

int count_increases(vec_input_it begin, vec_input_it end) {
    return std::transform_reduce(begin, std::prev(end),
        std::next(begin), 0,
        std::plus<>(),
        [](int l, int r) { return (l < r) ? 1 : 0; });
}

int main() {

    std::vector<int> inp;
    read_input(inp);

    int res1 = count_increases(inp.cbegin(), inp.cend());

    std::cout << "Part 1: " << res1 << '\n';

    // Part 2

    std::vector<int> inp_cpy(inp.size() - 2);

    // Sliding window
    for (size_t i = 0; i < inp.size() - 2; ++i) {
        inp_cpy[i] = inp[i] + inp[i + 1] + inp[i + 2];
    }

    int res2 = count_increases(inp_cpy.cbegin(), inp_cpy.cend());

    std::cout << "Part 2: " << res2 << '\n';

    return 0;
}
