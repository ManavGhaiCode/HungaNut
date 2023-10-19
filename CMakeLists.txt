cmake_minimum_required(VERSION "3.16")
project("HungaNut")

if (WIN32)
    set(${SDL2_LIBRARIES} "ThirdParty/SDL/lib/libSDL2.a")
endif (WIN32)

if (UNIX AND NOT APPLE)
    find_package(SDL2 REQUIRED)
    include_directories(${SDL2_INCLUDE_DIRS})
endif (UNIX AND NOT APPLE)

add_executable( "HungaNut"
    "HungaNut.h"
    "src/Engine.h"
    "src/Engine.cpp"
    "src/main.h"
    "src/Defines.h"
    "src/core/Window.h"
    "src/core/Window.cpp"
    "test/main.cpp"
)

target_include_directories("HungaNut" PRIVATE "src")

target_link_libraries("HungaNut" ${SDL2_LIBRARIES})