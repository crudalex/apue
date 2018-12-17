cmake_minimum_required(VERSION 3.12)
project(apue C)

set(CMAKE_C_STANDARD 11)
link_libraries(apue)

add_subdirectory(apue01_intro)
add_subdirectory(apue02_standard)

add_subdirectory(lsp01_intro)
add_subdirectory(lsp02_fileio)
add_subdirectory(lsp03_buffered_io)

