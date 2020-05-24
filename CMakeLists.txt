cmake_minimum_required(VERSION 3.0)
project(Compilers)

find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

add_subdirectory(01-naive-interpreter)
add_subdirectory(02-ast-tree)
add_subdirectory(03-visitors)
add_subdirectory(04-scopes)
