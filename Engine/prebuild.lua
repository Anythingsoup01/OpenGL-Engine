project "Engine"
    kind "StaticLib"
    language "C++"
    dialect "20"

    files
    {
        "src/*.cpp",
        "src/*.h",
        "vendor/*.cpp",
        "vendor/*.hpp",
    }

    includedirs
    {
        "src",
        "vendor/glm",
        "vendor/glfw/include",
        "vendor/Glad/include",
    }

    links
    {
        "GL",
        "Glad",
        "glfw",
    }
