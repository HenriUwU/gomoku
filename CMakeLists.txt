cmake_minimum_required(VERSION 3.22)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(Gomoku VERSION 1.0 LANGUAGES CXX)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")

add_compile_options(-Wall -Wextra -Werror -g3 -Ofast -fopenmp -Wpedantic)
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE "include")

target_link_libraries(${PROJECT_NAME} pthread sfml-graphics sfml-audio sfml-window sfml-system sfml-network)

find_package(SFML 2.6 COMPONENTS system window graphics network audio REQUIRED)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND mv "$<TARGET_FILE:${PROJECT_NAME}>" "..")