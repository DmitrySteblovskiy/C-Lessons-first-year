cmake_minimum_required(VERSION 3.28)

project(untitled1)

set(CMAKE_CXX_STANDARD 20)

#leak_sanitizer
#thread_sanitizer
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g")

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address")


add_executable(untitled1 main.cpp
        task2.cpp
        #structure_bindings.cpp
)
