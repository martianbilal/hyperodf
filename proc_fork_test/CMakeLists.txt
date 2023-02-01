cmake_minimum_required(VERSION 3.0.0)
project(proc_fork VERSION 0.1.0)

include_directories(/usr/include)
link_directories(/usr/lib/x86_64-linux-gnu/libaio.so)


message("CMAKE_C_FLAGS: ${CMAKE_C_FLAGS}")
message("CMAKE_LIBRARY_PATH: ${CMAKE_LIBRARY_PATH}")

include(CTest)
enable_testing()
find_library(PTHREAD_LIBRARY pthread)
find_library(AIO_LIBRARY NAMES aio PATHS /usr/lib/x86_64-linux-gnu/libaio.so)

add_executable(proc_fork main.c)

target_link_libraries(proc_fork ${PTHREAD_LIBRARY})
message("AIO Library: ${AIO_LIBRARY}")
target_link_libraries(proc_fork ${AIO_LIBRARY})


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
