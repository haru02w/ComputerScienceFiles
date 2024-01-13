# Setup the minimum version required of CMake to generate the Makefile
cmake_minimum_required(VERSION 3.5)

# define the name of our project
project(trabalho2 C)

# set the project to use C11
set(CMAKE_C_STANDARD 11)

set (CMAKE_C_FLAGS "-Werror -Wall -Wextra -Wpedantic -fsanitize=address")

# set debug mode
set(CMAKE_BUILD_TYPE Debug)

# set source directory
set(SRC_DIR "./src/")

set(ADDITIONAL_LIBRARIES m)
# Include Directories (invoke "-I" flags)
#include_directories( include )

set(CMAKE_EXPORT_COMPILE_COMMANDS true)

# Setup the list of source files (All of them)
file(GLOB_RECURSE SRCS ${SRC_DIR}/*.c)

# set the executable name
add_executable(${PROJECT_NAME} ${SRCS})

# link libraries
target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES} ${ADDITIONAL_LIBRARIES})
