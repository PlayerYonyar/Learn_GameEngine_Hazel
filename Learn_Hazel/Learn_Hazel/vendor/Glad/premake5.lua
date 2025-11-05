project "Glad"
	kind "StaticLib"
	language "C"
	staticruntime "off"
	warnings "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
--files:
	files
	{
		"include/glad/glad.h",
		"include/KHR/khrplatform.h",
		"src/glad.c",
	}

--includedirs:
	includedirs
	{
		"include"
	}
--filter:
	filter "system:windows"
	buildoptions { "-std=c11", "-lgdi32" }
		systemversion "latest"
		staticruntime "On"
--filter{}:		
	filter{ "system:windows", "configurations:Release"}
		buildoptions "/MT"
