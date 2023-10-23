cmake_minimum_required(VERSION "3.16")
project("HungaNut")

find_package(OpenGL REQUIRED)
set(CMAKE_CXX_STANDARD 17)

add_executable( "HungaNut"
    "src/main.h"
    "src/HungaNut.h"
    "src/core/Window.h"
    "src/core/Window.cpp"
    "src/Engine.h"
    "src/Engine.cpp"
    "test/main.cpp"

    # My libs
    "Libs/NutLogger/color.h"
    "Libs/NutLogger/NutLogger.h"
)

target_include_directories( "HungaNut" PRIVATE
    "src"
    "Libs"
)

target_link_libraries("HungaNut" OpenGL::GL glfw)