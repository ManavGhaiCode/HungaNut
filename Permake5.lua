workspace "HungaNut"
    architecture "x64"

    -- configs {
    --     "Debug",
    --     "Release"
    -- }

project "HungaNut"
    kind "StaticLib"
    language "C++"

    targetdir "Build"

    files {
        "src/**.h"
        "src/**.cpp"
    }

    include {
        "ThirdParty/SFML/include"
    }

    -- filter "configs:Debug"
    --     symbols "On"
    
    -- filter "configs:Release"
    --     oprimize "On"

project "Test"
    kind "ConsoleApp"

    files {
        "test/**.h"
        "test/**.cpp"
    }

    include {
        "ThirdParty/SFML/include"
    }