#include <gtest/gtest.h>
#include <vector>
#include <list>
#include "easyfind.hpp"

TEST(EasyFindTest, VectorTest) {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    // 正常系テスト
    auto it = easyfind(vec, 3);
    EXPECT_EQ(*it, 3);
    EXPECT_EQ(std::distance(vec.begin(), it), 2);  // インデックスが2であることを確認
    
    // 例外のテスト
    EXPECT_THROW(easyfind(vec, 10), std::runtime_error);
}

TEST(EasyFindTest, ListTest) {
    std::list<int> lst = {1, 2, 3, 4, 5};
    
    // 正常系テスト
    auto it = easyfind(lst, 4);
    EXPECT_EQ(*it, 4);
    
    // 例外のテスト
    EXPECT_THROW(easyfind(lst, 10), std::runtime_error);
}

TEST(EasyFindTest, EmptyContainerTest) {
    std::vector<int> empty_vec;
    EXPECT_THROW(easyfind(empty_vec, 1), std::runtime_error);
}
