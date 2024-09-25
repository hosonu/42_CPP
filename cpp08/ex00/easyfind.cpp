// test_easyfind.cpp
#include <gtest/gtest.h>
#include "easyfind.hpp" // Include your header file

TEST(EasyFindTest, FindExistingValue) {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    EXPECT_NO_THROW(easyfind(vec, 3)); // Should not throw
    EXPECT_EQ(*easyfind(vec, 3), 3); // Should return an iterator to 3
}

TEST(EasyFindTest, FindNonExistingValue) {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    EXPECT_THROW(easyfind(vec, 6), std::runtime_error); // Should throw
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
