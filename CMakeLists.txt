cmake_minimum_required(VERSION 3.16)

project(c_learn LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_executable(hello
    01hello.c
    getarea.c
    functions.c
    traverse.c
)

target_include_directories(hello PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

if(MSVC)
    target_compile_options(hello PRIVATE /W4 /utf-8)
else()
    target_compile_options(hello PRIVATE -Wall -Wextra -Wpedantic)
endif()
