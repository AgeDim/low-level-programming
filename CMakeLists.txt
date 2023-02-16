cmake_minimum_required(VERSION 3.24)
project(test)

set(CMAKE_CXX_STANDARD 14)

include(ExternalProject)
EXTERNALPROJECT_ADD(cereal
        GIT_REPOSITORY https://github.com/USCiLab/cereal.git
        PREFIX cereal
        SOURCE_DIR "${CMAKE_BINARY_DIR}/third-party/cereal")
include_directories(${CMAKE_BINARY_DIR}/third-party/cereal/include)

file(GLOB SRC "src/*/*.h" "src/*/*.cpp" "test/*.h" "test/*.cpp")

add_executable(test src/main.cpp ${SRC})
