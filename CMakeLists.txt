cmake_minimum_required(VERSION 3.17)
project(HomeWork32_1_2)

set (CMAKE_CXX_STANDARD 14)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_executable(HomeWork32_1_2 main.cpp)

target_link_libraries(HomeWork32_1_2 PRIVATE nlohmann_json::nlohmann_json)

