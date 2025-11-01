#include <algorithm>
#include <vector>
#include "deterministic.hpp"

int find_median_deterministic(const std::vector<int>& vec, int k){
    // Base case: if array is small, sort and return k-th element
    if (vec.size() <= 5) {
        std::vector<int> sorted = vec;
        std::sort(sorted.begin(), sorted.end());
        return sorted[k - 1];  // k is 1-indexed
    }

    // Step 1-2: Divide into groups of 5 and find medians
    std::vector<int> medians;
    for (size_t i = 0; i < vec.size(); i += 5) {
        size_t groupSize = std::min(size_t(5), vec.size() - i);
        std::vector<int> group(vec.begin() + i, vec.begin() + i + groupSize);
        std::sort(group.begin(), group.end());
        medians.push_back(group[groupSize / 2]);
    }

    // Step 3: Find median-of-medians recursively
    int pivot = find_median_deterministic(medians, (medians.size() + 1) / 2);

    // Step 4: Partition around pivot
    std::vector<int> LESS;
    std::vector<int> EQUAL;
    std::vector<int> GREATER;
    
    for (int x : vec) {
        if (x < pivot) {
            LESS.push_back(x);
        } else if (x == pivot) {
            EQUAL.push_back(x);
        } else {
            GREATER.push_back(x);
        }
    }

    int L = LESS.size();
    int E = EQUAL.size();

    // Step 5: Recurse or return based on partition sizes
    if (k <= L) {
        return find_median_deterministic(LESS, k);
    } else if (k <= L + E) {
        return pivot;  // Pivot is the k-th smallest
    } else {
        return find_median_deterministic(GREATER, k - L - E);
    }
}

