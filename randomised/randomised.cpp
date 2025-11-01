#include <iostream>
#include <vector>
#include <cstdlib>  // Used for std::rand
#include "randomised.hpp"

int find_median_randomised(const std::vector<int>& vec, int k){
    if (vec.size() == 1) return vec[0];

    int p = vec[std::rand() % vec.size()];  // Pick a random pivot

    std::vector<int> LESS;
    std::vector<int> GREATER;
    int L = 0;  // Set the initial length of LESS to 0

    // Partition the array into LESS and GREATER
    for (int x : vec) {
        if (x < p) {
            LESS.push_back(x);
            L++;  // Every time an element is added to LESS, increase the length by 1
        } else if (x > p) {
            GREATER.push_back(x);
        }
    }

    // Decide which partition to recurse into using the conditions
    if (L == k - 1) {
        return p; // Pivot is the k-th smallest
    } else if (L > k - 1) {
        return find_median_randomised(LESS, k);  // Recurse into LESS
    } else {
        return find_median_randomised(GREATER, k - L - 1);  // Recurse into GREATER
    }

}
