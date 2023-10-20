cmake_minimum_required(VERSION "3.16")
project("HungaNut")

if (WIN32)
    set(${SDL2_LIBRARIES} "ThirdParty/SDL/lib/libSDL2.a")
endif (WIN32)

if (UNIX AND NOT APPLE)
    find_package(SDL2 REQUIRED)
    include_directories(${SDL2_INCLUDE_DIRS})
endif (UNIX AND NOT APPLE)

find_package(OpenGL REQUIRED)

add_executable( "HungaNut"
    # engine files

    "HungaNut.h"
    "src/Engine.h"
    "src/Engine.cpp"
    "src/main.h"
    "src/Defines.h"
    "src/core/Window.h"
    "src/core/Window.cpp"
    "src/managers/LogManager.h"
    "src/managers/LogManager.cpp"
    
    # glad files

    "ThirdParty/glad/glad.h"
    "ThirdParty/glad/glad.c"

    # test project files

    "test/main.cpp"
)

target_include_directories( "HungaNut" PRIVATE 
    "src" 
    "ThirdParty"
    ${OPENGL_INCLUDE_DIR}
)

target_link_libraries( "HungaNut" 
    ${SDL2_LIBRARIES}
    ${OPENGL_LIBRARIES}
    ${CMAKE_DL_LIBS}
)