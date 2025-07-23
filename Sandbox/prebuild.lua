project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    dialect "20"

    files
    {
        "src/*.cpp",
        "src/*.h",
    }

    includedirs 
    {
        "$(WORKSPACEDIR)/Engine/src",
        "$(WORKSPACEDIR)/Engine/vendor/glfw/include",
        "$(WORKSPACEDIR)/Engine/vendor/Glad/include",
    }

    links
    {
        "Engine",
    }
