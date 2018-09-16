cmake_minimum_required(VERSION 3.12)
project(apue C)

set(CMAKE_C_STANDARD 11)
link_libraries(apue)

add_executable(main main.c)
add_executable(ls1 ls1.c)
add_executable(mycat mycat.c)
