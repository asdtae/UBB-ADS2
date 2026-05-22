cmake_minimum_required(VERSION 4.2)
project(02)

set(CMAKE_CXX_STANDARD 14)

add_executable(02 main.cpp)

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE
            -Wall
            -Wextra
            -Wpedantic
            -Wshadow
            #-Wconversion
            -Wcast-align
            -Wunused
            -Woverloaded-virtual
    )
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(${PROJECT_NAME} PRIVATE
            -fsanitize=address,undefined
            -fno-omit-frame-pointer
            -g
    )
    target_link_options(${PROJECT_NAME} PRIVATE
            -fsanitize=address,undefined
    )
endif()
