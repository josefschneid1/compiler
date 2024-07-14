cmake_minimum_required(VERSION 3.29.3)
project(compiler LANGUAGES CXX)
add_library(lexer)
target_sources(lexer
        PUBLIC
        FILE_SET CXX_MODULES FILES 
        src/lexer.ixx
)
target_compile_features(lexer PRIVATE cxx_std_20)
add_executable(${PROJECT_NAME}
        src/main.cpp
)
target_link_libraries(${PROJECT_NAME} lexer)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
