cmake_minimum_required(VERSION 3.12)
project(apue C)

set(CMAKE_C_STANDARD 11)
link_libraries(apue)

add_executable(getcputc getcputc.c)
add_executable(hello hello.c)
add_executable(ls1 ls1.c)
add_executable(mycat mycat.c)
add_executable(shell1 shell1.c)
add_executable(shell2 shell2.c)
add_executable(testerror testerror.c)
add_executable(uidgid uidgid.c)
