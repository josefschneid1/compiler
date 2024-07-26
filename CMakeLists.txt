cmake_minimum_required(VERSION 3.29.3)
project(compiler LANGUAGES CXX)

find_package(Python3 COMPONENTS Interpreter REQUIRED)

add_custom_command(
    OUTPUT lexer.ixx
    COMMAND ${Python3_EXECUTABLE}
    ${CMAKE_CURRENT_SOURCE_DIR}/gen/lexer_gen.py
    ${CMAKE_CURRENT_BINARY_DIR}/lexer.ixx
    ${CMAKE_CURRENT_BINARY_DIR}/token.json
    DEPENDS gen/token.json gen/lexer_gen.py gen/templates/lexer_template.txt
)

add_library(lexer)

target_sources(lexer
        PUBLIC
        FILE_SET CXX_MODULES FILES 
        ${CMAKE_CURRENT_BINARY_DIR}/lexer.ixx
)

add_executable(${PROJECT_NAME}
        src/main.cpp
)
target_link_libraries(${PROJECT_NAME} lexer)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)