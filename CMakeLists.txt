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

set (CMAKE_CXX_STANDARD 17)

add_executable( "HungaNut"
    # engine files

    "HungaNut.h"
    "src/Engine.h"
    "src/Engine.cpp"
    "src/main.h"
    "src/Defines.h"
    "src/core/Window.h"
    "src/core/Window.cpp"

    # managers
    "src/managers/LogManager.h"
    "src/managers/LogManager.cpp"
    "src/managers/RenderManager.h"
    "src/managers/RenderManager.cpp"
    "src/managers/InputManager.h"
    "src/managers/InputManager.cpp"

    # Input stuff
    "src/Input/InputKeys.h"
    "src/Input/Mouse.h"
    "src/Input/Mouse.cpp"
    "src/Input/KeyBoard.h"
    "src/Input/KeyBoard.cpp"

    # graphics files
    "src/core/graphics/mesh.h"
    "src/core/graphics/mesh.cpp"    
    "src/core/graphics/shader.h"
    "src/core/graphics/shader.cpp"    
    "src/core/graphics/RenderPipe.h"
    "src/core/graphics/RenderPipe.cpp"
    
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