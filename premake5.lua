workspace "Slice"
    architecture "x64"

    configurations{
        "Debug",
        "Release"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}" -- BuildName/x64/Windows


--- include directories relative to root folder (solution directory)
IncludeDir = {}
-- IncludeDir["glad"] = "dependencies/glad/include"
-- IncludeDir["GLFW"] = "dependencies/GLFW/include"
-- IncludeDir["IMGUI"] = "dependencies/IMGUI/include"

-- include "dependencies/glad"
-- include "dependencies/GLFW"
-- include "dependencies/IMGUI"

project "Slice"
    location "Slice"
    kind "ConsoleApp"
    language "C++"

    targetdir("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. outputdir .. "/%{prj.name}")

    files{
        "%{prj.name}/include/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs{
        -- "%{prj.name}/src/utils",

        -- "dependencies/glm/include",
        -- "dependencies/stb_img/include",
        -- "dependencies/assimp/includes",

        -- "%{IncludeDir.glad}",
        -- "%{IncludeDir.GLFW}",
        -- "%{IncludeDir.IMGUI}",
    }

    libdirs { 
        -- "dependencies/assimp/libs"
    }


    links{  
        --- The name of the projects
        -- "glad",
    
        -- "GLFW",
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0"

        defines{
            "SLICE_PLATFORM_WINDOWS",
            "_UNICODE",
            "UNICODE"
        }

    filter "configurations:Debug"
        defines "SLICE_DEBUG"
        symbols "On"
        buildoptions "/MT"

    filter "configurations:Release"
        defines "SLICE_RELEASE"
        optimize "On"
        buildoptions "/MT"

    filter { "system:windows", "configurations:Release" }
        buildoptions "/MT"