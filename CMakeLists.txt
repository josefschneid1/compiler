cmake_minimum_required(VERSION 3.20.5 FATAL_ERROR)

project(compiler LANGUAGES CXX)

find_package(Catch2 REQUIRED)

add_library(core OBJECT
        src/Lexer.cpp
        src/Parser.cpp
)

target_include_directories(core
    PUBLIC
    include/
)

set_target_properties(core
    PROPERTIES
        CXX_STANDARD 20
        CXX_EXTENSIONS OFF
        CXX_STANDARD_REQUIRED TRUE
)

add_executable(main src/main.cpp)
target_link_libraries(main core)

set_target_properties(main
    PROPERTIES
        CXX_STANDARD 20
        CXX_EXTENSIONS OFF
        CXX_STANDARD_REQUIRED TRUE
)

enable_testing()

add_executable(comptest 
    test/test_lexer.cpp
    test/test_tree.cpp
    test/test_parser.cpp
)

target_link_libraries(comptest core Catch2::Catch2WithMain)

set_target_properties(comptest
    PROPERTIES
        CXX_STANDARD 20
        CXX_EXTENSIONS OFF
        CXX_STANDARD_REQUIRED TRUE
)

include(Catch)
catch_discover_tests(comptest)

#find_package(opencv REQUIRED)
#find_package(boost REQUIRED)
#target_include_directories(main PUBLIC ${OpenCV_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})
#target_link_libraries(main ${OpenCV_LIBS} ${Boost_LIBRARIES})