cmake_minimum_required(VERSION 3.31)
project(boost_test)
set(CMAKE_CXX_STANDARD 20)

find_package(glad)
find_package(glfw3)

add_executable(boost_test main.cpp)

target_link_libraries(boost_test PRIVATE #[[libassert::assert]] glad::glad glfw)

# Hei Arian <3
# Mathias var her