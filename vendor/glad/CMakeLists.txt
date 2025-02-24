cmake_minimum_required(VERSION 3.10)
project(glad)

# Build glad as a static library from its source file
add_library(glad STATIC src/glad.c)

# Expose the include directory so that consumers of glad can find its headers
target_include_directories(glad PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)