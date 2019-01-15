cmake_minimum_required(VERSION 3.12)

# Ensure all build projects arrive in the same directory
set(INSTALL_DIR ${PROJECT_BINARY_DIR}/out)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${INSTALL_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${INSTALL_DIR})

add_subdirectory(main)
