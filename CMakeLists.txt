cmake_minimum_required(VERSION "3.16")
project("HungaNut")

find_package(Threads REQUIRED)
set(LIBSDL_DIR ${CMAKE_SOURCE_DIR}/ThirdParty/SDL2/lib)
set(LIBBOX2D ${CMAKE_SOURCE_DIR}/ThirdParty/Box2d/lib)

add_library("HungaNut" STATIC
    "src/Engine.h"
    "src/Engine.cpp"
    "src/Window.h"
    "src/Window.cpp"
    "src/Input/InputManager.h"
    "src/Input/InputManager.cpp"
    "src/Input/KeyBinds.h"
    "src/Input/KeyBoard.h"
    "src/Input/Mouse.h"
    "src/Renderer/Renderer.h"
    "src/Renderer/Renderer.cpp"
    "src/API/Rendering.h"
    "src/API/Rendering.cpp"
    "src/API/Input.h"
    
    "src/Logging/color.h"
    "src/Logging/format.h"
    "src/Logging/NutLogger.h"
    "src/log.h"
    "src/main.h"
    "src/HungaNut.h"
)

target_include_directories("HungaNut" PUBLIC
    "src"
    "ThirdParty/SDL2/include"
    "ThirdParty/Box2d/include"
)

target_link_libraries("HungaNut" PRIVATE
    ${LIBSDL_DIR}/libSDL2d.a
    ${LIBSDL_DIR}/libSDL2_image.a
    ${LIBBOX2D}/libbox2d.a
    
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