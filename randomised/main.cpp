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