cmake_minimum_required(VERSION "3.16")
project("HungaNut")

find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

add_executable( "HungaNut"
    "src/Engine.h"
    "src/Engine.cpp"
    "src/core/Window.h"
    "src/core/Window.cpp"
    "src/core/Renderer.h"
    "src/core/Renderer.cpp"
    "src/log.h"
    "src/main.h"
    "src/HungaNut.h"
    "test/main.cpp"

    # My libs
    "Libs/NutLogger/NutLogger.h"
    "Libs/NutLogger/color.h"
    "Libs/NutLogger/format.h"
)

target_include_directories( "HungaNut" PRIVATE
    "src"
    "Libs"
    ${SDL2_INCLUDE_DIRS}
    ${SDL2_IMAGE_INCLUDE_DIRS}
)

target_link_libraries( "HungaNut"
    OpenGL::GL
    ${SDL2_LIBRARIES}
    ${SDL2_IMAGE_LIBRARIES}
)