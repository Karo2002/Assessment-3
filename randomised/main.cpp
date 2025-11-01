#include <gtest/gtest.h>
#include <vector>
#include <algorithm> 
#include "randomised.hpp" 

// Test a small array in ascending order
TEST(QuickselectTest, SmallAscending) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    EXPECT_EQ(find_median_randomised(arr, 1), 1);
    EXPECT_EQ(find_median_randomised(arr, 3), 3);
    EXPECT_EQ(find_median_randomised(arr, 5), 5);
}

// Test a small array in descending order
TEST(QuickselectTest, SmallDescending) {
    std::vector<int> arr = {5, 4, 3, 2, 1};
    EXPECT_EQ(find_median_randomised(arr, 1), 1);
    EXPECT_EQ(find_median_randomised(arr, 2), 2);
    EXPECT_EQ(find_median_randomised(arr, 5), 5);
}

// Test an array with random order
TEST(QuickselectTest, RandomOrder) {
    std::vector<int> arr = {7, 2, 9, 1, 5};
    EXPECT_EQ(find_median_randomised(arr, 1), 1);
    EXPECT_EQ(find_median_randomised(arr, 3), 5);
    EXPECT_EQ(find_median_randomised(arr, 5), 9);
}

// Test array with duplicates
TEST(QuickselectTest, Duplicates) {
    std::vector<int> arr = {4, 2, 4, 1, 3, 2};
    EXPECT_EQ(find_median_randomised(arr, 1), 1);
    EXPECT_EQ(find_median_randomised(arr, 2), 2);
    EXPECT_EQ(find_median_randomised(arr, 3), 2);
    EXPECT_EQ(find_median_randomised(arr, 4), 3);
    EXPECT_EQ(find_median_randomised(arr, 6), 4);
}

// Test single element array
TEST(QuickselectTest, SingleElement) {
    std::vector<int> arr = {42};
    EXPECT_EQ(find_median_randomised(arr, 1), 42);
}

// Test two element array
TEST(QuickselectTest, TwoElements) {
    std::vector<int> arr = {10, 5};
    EXPECT_EQ(find_median_randomised(arr, 1), 5);
    EXPECT_EQ(find_median_randomised(arr, 2), 10);
}