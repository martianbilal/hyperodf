cmake_minimum_required(VERSION 3.0.0)
project(proc_fork VERSION 0.1.0)

include(CTest)
enable_testing()
find_library(PTHREAD_LIBRARY pthread)

add_executable(proc_fork main.c)

target_link_libraries(proc_fork ${PTHREAD_LIBRARY})


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
