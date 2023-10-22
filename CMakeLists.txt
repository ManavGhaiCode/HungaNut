cmake_minimum_required(VERSION "3.16")
project("HungaNut")

find_package(OpenGL REQUIRED)

add_executable( "HungaNut"
    "src/main.h"
    "src/HungaNut.h"
    "test/main.cpp"
)

target_link_directories( "HungaNut" PRIVATE
    "src"
)

target_link_libraries("HungaNut" OpenGL::GL glfw)