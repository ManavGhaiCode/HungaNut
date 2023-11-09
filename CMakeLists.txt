cmake_minimum_required(VERSION "3.16")
project("HungaNut")

add_library("HungaNut" STATIC
    "src/Engine.cpp"
    "src/Engine.h"

    "src/main.h"
    "src/HungaNut.h"
)

target_include_directories("HungaNut" PRIVATE
    "include"
    "ThirdParty/SFML/include"
)

project("Test")

add_executable("Test"
    "test/test.cpp"
)

target_link_libraries("Test" PRIVATE
    "HungaNut"
)

target_include_directories("Test" PUBLIC
    "src"
)