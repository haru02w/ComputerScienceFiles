cmake_minimum_required(VERSION 3.25)
# Set project name and version
project(main VERSION 0.1)

# set clang-format flags
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# set cmake debug target
set(CMAKE_BUILD_TYPE Debug)

# Set CPP Standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# gathers all source code files
file(GLOB_RECURSE SRCS CONFIGURE_DEPENDS "src/*.c")
add_executable(${PROJECT_NAME} ${SRCS})
target_include_directories(${PROJECT_NAME} PUBLIC "include")
find_package(OpenMP)

# https://cmake.org/cmake/help/latest/manual/cmake-modules.7.html
# find_package(Curses REQUIRED)
#
# target_include_directories(${PROJECT} PUBLIC ${CURSES_INCLUDE_DIRS})
#
target_link_libraries(${PROJECT_NAME} PUBLIC OpenMP::OpenMP_C m)
# ...............................................................

# compiles to executable

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
