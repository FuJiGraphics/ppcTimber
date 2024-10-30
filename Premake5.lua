workspace "Solution"
	startproject "Timber"
	architecture "x86_64"

	configurations
	{
		"Debug",
		"Release",
	}

	flags
	{
		"MultiProcessorCompile"
	}

project "Timber"
	location "Timber"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
	staticruntime "off"
	systemversion "latest"

-- pchheader "pch.h"
-- pchsource "%{IncludeDir.VegaEngine2}/src/pch.cpp"

targetdir("%{wks.location}/Vendor/%{prj.name}/lib/%{cfg.buildcfg}/")
objdir("%{wks.location}/Vendor/%{prj.name}/bin-int/%{cfg.buildcfg}/")

debugdir("%{wks.location}/vendor/SFML-2.6.1/bin/")

files
{
	"**.cpp",
	"**.h",
}

includedirs
{
	"%{wks.location}/%{prj.name}/",
	"%{wks.location}/vendor/SFML-2.6.1/include/",
}

libdirs
{
	"%{wks.location}/vendor/SFML-2.6.1/lib/%{cfg.buildcfg}/",
}

links
{
	"sfml-audio.lib",
	"sfml-graphics.lib",
	"sfml-main.lib",
	"sfml-network.lib",
	"sfml-system.lib",
	"sfml-window.lib",
}

filter "system:Windows"

defines
{
	"PPC_PLATFORM_WINDOWS",
}

filter "configurations:Debug"
	defines "PPC_DEBUG"
	runtime "Debug"
	symbols "On"

filter "configurations:Release"
	defines "PPC_RELEASE"
	runtime "Release"
	optimize "On"
