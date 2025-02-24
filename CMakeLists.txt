cmake_minimum_required(VERSION 3.10)
project(Z-Game VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(vendor/glfw)
add_subdirectory(vendor/ImGui)
add_subdirectory(vendor/glad)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(Z-Game src/main.cpp src/Shader.cpp)

target_link_libraries(Z-Game PRIVATE glfw imgui glad opengl32)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Z-Game)
