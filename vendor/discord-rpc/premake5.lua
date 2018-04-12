-- Source: https://github.com/discordapp/discord-rpc/releases/tag/v3.0.0

project "discord-rpc"
	language "C++"
	kind "StaticLib"
	targetname "discord-rpc"

	includedirs {
		"include",
		"thirdparty/rapidjson/include",
	}

	links "Psapi"

	defines {
		"DISCORD_DISABLE_IO_THREAD",
	}

	warnings "Extra"

	disablewarnings {
		4100, -- unreferenced formal parameter
		4514, -- unreferenced inline
		4625, -- copy constructor deleted
		5026, -- move constructor deleted
		4626, -- move assignment operator deleted
		4668, -- not defined preprocessor macro
		4710, -- function not inlined
		4711, -- function was inlined
		4820, -- structure padding
		4946, -- reinterpret_cast used between related classes
		5027, -- move assignment operator was implicitly defined as deleted
	}

	files {
		-- MTA
		"premake5.lua",

		-- Include
		"include/**.h",

		-- Source
		"src/backoff.h",
		"src/connection_win.cpp",
		"src/connection.h",
		"src/discord_register_win.cpp",
		"src/discord_rpc.cpp",
		"src/msg_queue.h",
		"src/rpc_connection.cpp",
		"src/rpc_connection.h",
		"src/serialization.cpp",
		"src/serialization.h",

		-- Third-Party
		"./thirdparty/rapidjson/include/**.h",
	}

	vpaths { 
		["Include/*"] = "include/**.h",
		["Include/thirdparty/*"] = "thirdparty/rapidjson/include/**.h",
		["Source/*"] = { "src/**.cpp", "src/**.h" },
		["*"] = "premake5.lua"
	}

	filter "architecture:x64"
		flags { "ExcludeFromBuild" } 
	filter "system:not windows"
		flags { "ExcludeFromBuild" } 
