cmake_minimum_required (VERSION 3.8)

set(tmaster_project_name "tmaster")

message("---------- Проект trex master process ----------")

project (${tmaster_project_name} VERSION 1.0.0 LANGUAGES CXX)

cmake_policy(SET CMP0144 OLD)
if(POLICY CMP0167)
	cmake_policy(SET CMP0167 OLD)
endif()

set(tmaster_version_major 1)
set(tmaster_version_minor 0)
set(tmaster_version_patch 0)
set(tmaster_version_string "${tmaster_version_major}.${tmaster_version_minor}.${tmaster_version_patch}")

set(tmaster_project_dir ${trex_source_dir}/tmaster)
set(tmaster_source_dir ${tmaster_project_dir}/src)
set(tmaster_include_dir ${tmaster_project_dir}/include)

message("tmaster_project_dir: ${tmaster_project_dir}")
message("tmaster_source_dir: ${tmaster_source_dir}")
message("tmaster_include_dir: ${tmaster_include_dir}")

set(sys_home_dir $ENV{HOME})
set(trex_env_dir ${sys_home_dir}/.trex)

configure_file(${tmaster_include_dir}/config.h.in ${tmaster_include_dir}/config.h @ONLY)


if(UNIX)
	add_definitions(-DBOOST_BIND_GLOBAL_PLACEHOLDERS)

	if(${CMAKE_BUILD_TYPE} STREQUAL "debug")
		#message("---------- Конфигурация debug ----------")
		add_compile_options(
			-std=c++23
			-g
			-static-libgcc
			-static-libstdc++
			-fpic
			#-fsanitize=address
			#-fsanitize=undefined
			#-fsanitize=thread

			### Флаги ошибок и предупреждений ###	
			-ftemplate-backtrace-limit=0	
			-fpermissive
			-Wall
			-Wextra 
			-pedantic 
			#-Werror
    		-Wno-non-virtual-dtor 
			-Wno-dangling-reference # Подавление dangling-reference
			-Wno-dev
		)
	elseif(${CMAKE_BUILD_TYPE} STREQUAL "release")
		#message("---------- Конфигурация RELEASE ----------")
		add_compile_options(
			-std=c++23
			-O3
			-static-libgcc
			-static-libstdc++
			-fpic

			### Флаги ошибок и предупреждений ###
			-fpermissive
			-Wall 
			-Wextra 
			-pedantic 
			#-Werror
    		-Wno-non-virtual-dtor 
			-Wno-dangling-reference
			-Wno-dev
		)
	endif()
elseif(WIN32)
endif()

set(tmaster_sources
		${tmaster_source_dir}/main.cpp
    )

if(UNIX)
	message("----- Подключение библиотек для linux -----")

	#########################################################################

	#message("--- Подключение Boost для LINUX ---")	
	#
	#set(boost_additional_versions "1.87" "1.87.0")
	#set(boost_root "/mnt/d/repo/boost_1_87_0_linux")
	#set(boost_librarydir "/mnt/d/repo/boost_1_87_0_linux/stage/lib")
	#set(BOOST_ADDITIONAL_VERSIONS on) 
	#set(BOOST_USE_MULTITHREADED on)  
	#set(BOOST_USE_STATIC_RUNTIME off) 
	#find_package(Boost 1.87 REQUIRED program_options) # filemaster)
	#
	#if(BOOST_FOUND)
	#	message("boost для linux найден")
	#
	#	set(boost_include_dirs "/mnt/d/repo/boost_1_87_0_linux")
	#
	#	message("boost_include_dirs: ${boost_include_dirs}")
	#	message("boost_librarydir: ${boost_librarydir}")
	#else()
	#	message(FATAL_ERROR "boost для linux не найден!!!")
	#endif()

	set(tmaster_additional_librariess
		pthread
		#Boost::filemaster
		#Boost::program_options
		)
elseif(WIN32)
endif()

### make & install ###
add_executable(${tmaster_project_name}  ${tmaster_sources})

### Включяемые файлы (*.h) master_server ###
target_include_directories(${tmaster_project_name} PUBLIC 
	${trex_include_dir} # Общие включаемые файлы
	${trex_lib_dir} # Включаемые файлы сторонних библиотек	
	${tmaster_include_dir} # Иключаемые файлы tmaster
	#${boost_include_dirs} # Включаемые файлы boost
)

target_link_libraries(${tmaster_project_name} ${tmaster_additional_libraries}) # Включаемые библиотеки

install(TARGETS ${tmaster_project_name} DESTINATION ${CMAKE_INSTALL_DIR})
