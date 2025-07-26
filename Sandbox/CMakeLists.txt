set(SRCS
    src/SandboxApp.cpp
)
add_executable(Sandbox ${SRCS})
set_property(TARGET Sandbox PROPERTY CXX_STANDARD 20)

target_include_directories(Sandbox PRIVATE
    ${CMAKE_SOURCE_DIR}/Engine/src
    ${CMAKE_SOURCE_DIR}/Engine/vendor/glfw/include
    ${CMAKE_SOURCE_DIR}/Engine/vendor/Glad/include
    ${CMAKE_SOURCE_DIR}/Engine/vendor/spdlog/include
)

target_link_libraries(Sandbox
    Engine
)

target_compile_definitions(Sandbox PUBLIC GDEFINES)
