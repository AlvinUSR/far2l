cmake_minimum_required (VERSION 3.8)

set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER  "g++")
set(CMAKE_CXX_STANDARD 23)

if(${CMAKE_BUILD_TYPE} STREQUAL "debug")
    message("---------- Конфигурация debug ----------")
    add_compile_definitions(__debug__)
elseif(${CMAKE_BUILD_TYPE} STREQUAL "release")
    message("---------- Конфигурация release ----------")
    add_compile_definitions(__release__)
endif()

if(UNIX)
    add_compile_definitions(__unix__)
elseif(WIN32)
    add_compile_definitions(__win__)
endif() 

set(trex_project_name "trex")
	
project (${trex_project_name} VERSION 1.0.0 LANGUAGES CXX)

set(trex_project_dir ${CMAKE_SOURCE_DIR})
set(trex_include_dir ${trex_project_dir}/include)
set(trex_lib_dir ${trex_project_dir}/lib)
set(trex_source_dir ${trex_project_dir}/src)
message("trex_project_dir: ${trex_project_dir}")
message("trex_include_dir: ${trex_include_dir}")
message("trex_lib_dir: ${trex_lib_dir}")
message("trex_source_dir: ${trex_source_dir}")

# Включите подпроекты
