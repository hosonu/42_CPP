cmake_minimum_required(VERSION 3.10)
project(easyfind_test)

# C++標準の設定
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Google Testのダウンロードと設定
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

# テストの実行ファイルの設定
add_executable(easyfind_test test_easyfind.cpp)
target_link_libraries(easyfind_test gtest_main)

# テストの自動検出を有効化
include(GoogleTest)
gtest_discover_tests(easyfind_test)
