cmake_minimum_required(VERSION 3.20.5 FATAL_ERROR)

project(compiler LANGUAGES CXX)

find_package(Catch2 REQUIRED)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(core OBJECT
		include/Lexer.hpp
        src/Lexer.cpp
		include/Parser.hpp
        src/Parser.cpp
		include/Tree.hpp
)

target_include_directories(core
    PUBLIC
    include/
)

add_executable(main src/main.cpp)
target_link_libraries(main core)

enable_testing()

add_executable(comptest 
    test/test_lexer.cpp
    test/test_tree.cpp
    test/test_parser.cpp
	test/test_main.cpp
)

target_link_libraries(comptest core Catch2::Catch2)

include(Catch)
catch_discover_tests(comptest)