cmake_minimum_required(VERSION 3.5.1)
project(learn_open_GL VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(glfw3 REQUIRED)
# # Specify the include directory
# include_directories(/opt/homebrew/opt/glfw/include)

# # Specify the library path
# link_directories(/opt/homebrew/opt/glfw/lib)
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/external)

add_executable(main src/main.cpp external/glad.c)

# include_directories(${GLFW_INCLUDE_DIRS})
target_link_libraries(main glfw) # This assumes the imported target is named 'glfw'

option(GLFW_BUILD_EXAMPLES "Build the GLFW example programs" OFF)
option(GLFW_BUILD_TESTS "Build the GLFW test programs" OFF)
option(GLFW_BUILD_DOCS "Build the GLFW documentation" OFF)
option(GLFW_INSTALL "Generate installation target" OFF)
option(GLFW_DOCUMENT_INTERNALS "Include internals in documentation" OFF)

