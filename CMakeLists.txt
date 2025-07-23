cmake_minimum_required(VERSION 3.30)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(OpenGL-Engine LANGUAGES C CXX)
set(GDEFINES
    GLFW_INCLUDE_NONE
)

add_subdirectory(Engine/vendor/Glad)
add_subdirectory(Sandbox)
add_subdirectory(Engine)
add_subdirectory(Engine/vendor/glfw)
