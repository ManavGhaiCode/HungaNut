cmake_minimum_required(VERSION "3.16")
project("HungaNut")

find_package(Threads REQUIRED)
set(LIBSDL_DIR ${CMAKE_SOURCE_DIR}/ThirdParty/SDL2/lib)

add_library("HungaNut" STATIC
    "src/Engine.cpp"
    "src/Engine.h"

    "src/main.h"
    "src/HungaNut.h"
)

target_include_directories("HungaNut" PUBLIC
    "src"
    "ThirdParty/SDL2/include"
)

target_link_libraries("HungaNut" PRIVATE
    ${LIBSDL_DIR}/libSDL2d.a
    ${CMAKE_DL_LIBS}
    Threads::Threads
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