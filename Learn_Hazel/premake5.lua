workspace "Learn_Hazel"
	architecture "x64"
    startproject "Sandbox"
	configurations
	{
		"Debug",
		"Release",
		"Dist",
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Learn_Hazel"
    location "Learn_Hazel"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin/int/" .. outputdir .. "/%{prj.name}")

    pchheader "hzpch.h"
    pchsource "Learn_Hazel/src/hzpch.cpp"

files
{
    "%{prj.name}/src/**.h",
    "%{prj.name}/src/**.cpp",
}
includedirs
{
    "%{prj.name}/src",
    "%{prj.name}/vendor/spdlog/include",

}


filter "system:windows"
    cppdialect "C++17"
    staticruntime "On"
    systemversion "latest"
defines
{
"HZ_PLATFORM_WINDOWS",
"HZ_BUILD_DLL",

}

postbuildcommands
{
    ("{MKDIR} ../bin/" .. outputdir .. "/Sandbox"),
    ("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox"),
}

filter "configurations:Debug"
    defines "HZ_DEBUG"
    buildoptions "/utf-8"
    buildoptions "/MDd"
    symbols "On"

filter "configurations:Release"
    defines "HZ_RELERASE"
    buildoptions "utf-8"
    buildoptions "/MD"
    optimize "On"
filter "configurations:Dist"
    defines "HZ_DIST"
    buildoptions "utf-8"
    buildoptions "/MD"
    optimize "On"
    
project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin/int/" .. outputdir .. "/%{prj.name}")
files
{
    "%{prj.name}/src/**.h",
    "%{prj.name}/src/**.cpp"
}
includedirs
{
    "Learn_Hazel/src",
    "Learn_Hazel/vendor/spdlog/include",
    "Learn_Hazel/vendor",

}
links
{
    "Learn_Hazel"
}
filter "system:windows"
    cppdialect "C++17"
    staticruntime "On"
    systemversion "latest"
defines
{
"HZ_PLATFORM_WINDOWS",
}


filter "configurations:Debug"
    defines "HZ_DEBUG"
    buildoptions "/utf-8"
    buildoptions "/MDd"
    symbols "On"

filter "configurations:Release"
    defines "HZ_RELERASE"
    buildoptions "/utf-8"
    buildoptions "/MD"
    optimize "On"
filter "configurations:Dist"
    defines "HZ_DIST"
    buildoptions "/utf-8"
    buildoptions "/MD"
    optimize "On"
