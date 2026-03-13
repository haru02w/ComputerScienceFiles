cmake_minimum_required(VERSION 3.25)
# Set project name and version
project(main VERSION 0.1)

# set clang-format flags
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# set cmake debug target
set(CMAKE_BUILD_TYPE Debug)

# Set CPP Standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# gathers all source code files
file(GLOB_RECURSE SRCS CONFIGURE_DEPENDS "src/*.cpp")
add_executable(${PROJECT_NAME} ${SRCS})
target_include_directories(${PROJECT_NAME} PUBLIC "include")

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} GL
                      GLU glut)
# ...............................................................

# compiles to executable

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
