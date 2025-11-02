#include <gtest/gtest.h>
#include <vector>
#include <algorithm> 
#include "deterministic.hpp" 

// Test a small array in ascending order
TEST(QuickselectTest, SmallAscending) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    EXPECT_EQ(find_median_deterministic(arr, 1), 1);
    EXPECT_EQ(find_median_deterministic(arr, 3), 3);
    EXPECT_EQ(find_median_deterministic(arr, 5), 5);
}

// Test a small array in descending order
TEST(QuickselectTest, SmallDescending) {
    std::vector<int> arr = {5, 4, 3, 2, 1};
    EXPECT_EQ(find_median_deterministic(arr, 1), 1);
    EXPECT_EQ(find_median_deterministic(arr, 2), 2);
    EXPECT_EQ(find_median_deterministic(arr, 5), 5);
}

// Test an array with random order
TEST(QuickselectTest, RandomOrder) {
    std::vector<int> arr = {7, 2, 9, 1, 5};
    EXPECT_EQ(find_median_deterministic(arr, 1), 1);
    EXPECT_EQ(find_median_deterministic(arr, 3), 5);
    EXPECT_EQ(find_median_deterministic(arr, 5), 9);
}

// Test array with duplicates
TEST(QuickselectTest, Duplicates) {
    std::vector<int> arr = {4, 2, 4, 1, 3, 2};
    EXPECT_EQ(find_median_deterministic(arr, 1), 1);
    EXPECT_EQ(find_median_deterministic(arr, 2), 2);
    EXPECT_EQ(find_median_deterministic(arr, 3), 2);
    EXPECT_EQ(find_median_deterministic(arr, 4), 3);
    EXPECT_EQ(find_median_deterministic(arr, 6), 4);
}

// Test array with all same elements
TEST(DeterministicSelectTest, AllSame) {
    std::vector<int> arr = {7, 7, 7, 7, 7};
    EXPECT_EQ(find_median_deterministic(arr, 1), 7);
    EXPECT_EQ(find_median_deterministic(arr, 3), 7);
    EXPECT_EQ(find_median_deterministic(arr, 5), 7);
}

// Test array with many duplicates
TEST(DeterministicSelectTest, ManyDuplicates) {
    std::vector<int> arr = {5, 3, 5, 1, 3, 5, 1, 3, 5};
    // Sorted: [1, 1, 3, 3, 3, 5, 5, 5, 5]
    EXPECT_EQ(find_median_deterministic(arr, 1), 1);
    EXPECT_EQ(find_median_deterministic(arr, 2), 1);
    EXPECT_EQ(find_median_deterministic(arr, 5), 3);
    EXPECT_EQ(find_median_deterministic(arr, 9), 5);
}

// Test single element array
TEST(QuickselectTest, SingleElement) {
    std::vector<int> arr = {42};
    EXPECT_EQ(find_median_deterministic(arr, 1), 42);
}

// Test two element array
TEST(QuickselectTest, TwoElements) {
    std::vector<int> arr = {10, 5};
    EXPECT_EQ(find_median_deterministic(arr, 1), 5);
    EXPECT_EQ(find_median_deterministic(arr, 2), 10);
}

// Test a large array
TEST(QuickselectTest, LargeArray1) {
    std::vector<int> arr = {
        34, 7, 23, 32, 5, 62, 78, 0, 12, 99,
        21, 54, 11, 8, 17, 46, 3, 29, 50, 19
    };
    EXPECT_EQ(find_median_deterministic(arr, 1), 0);
    EXPECT_EQ(find_median_deterministic(arr, 10), 21);
    EXPECT_EQ(find_median_deterministic(arr, 20), 99);
}

// Test a larger array
TEST(QuickselectTest, LargeArray2) {
    std::vector<int> arr = {
        100, 23, 54, 2, 76, 12, 89, 34, 67, 45,
        90, 11, 38, 29, 50, 61, 18, 3, 72, 6,
        42, 81, 5, 14, 7, 20, 55, 9, 31, 19
    };
    EXPECT_EQ(find_median_deterministic(arr, 1), 2);
    EXPECT_EQ(find_median_deterministic(arr, 5), 7);
    EXPECT_EQ(find_median_deterministic(arr, 10), 18);
    EXPECT_EQ(find_median_deterministic(arr, 15), 31);
    EXPECT_EQ(find_median_deterministic(arr, 30), 100);
}
