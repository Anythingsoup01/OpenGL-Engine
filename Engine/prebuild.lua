project "Engine"
    kind "StaticLib"
    language "C++"
    dialect "20"

    pch "src/epch.h"

    files
    {
        "src/*.cpp",
        "src/*.h",
        "vendor/glm/*.cpp",
        "vendor/glm/*.hpp",
    }

    includedirs
    {
        "src",
        "vendor/glm",
        "vendor/glfw/include",
        "vendor/Glad/include",
        "vendor/spdlog/include",
    }

    links
    {
        "GL",
        "Glad",
        "glfw",
    }

    filter "configurations:Debug"
        defines "E_DEBUG"

    filter "configurations:Release"
        defines "E_RELEASE"
