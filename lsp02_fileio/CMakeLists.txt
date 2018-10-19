cmake_minimum_required(VERSION 3.10)
project(apue C)

set(CMAKE_C_STANDARD 11)

add_executable(poll poll.c)
add_executable(sparse sparse.c)
add_executable(truncate truncate.c)
add_executable(write write.c)
add_executable(select select.c)
