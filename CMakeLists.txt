cmake_minimum_required(VERSION "3.16")
project("HungaNut")

find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)

add_executable( "HungaNut"
    "src/Engine.h"
    "src/Engine.cpp"
    "src/main.h"
    "src/HungaNut.h"
    "test/main.cpp"
)

target_include_directories( "HungaNut" PRIVATE
    "src"
    ${SDL2_INCLUDE_DIRS}
)

target_link_libraries( "HungaNut"
    OpenGL::GL
    ${SDL2_LIBRARIES}
)