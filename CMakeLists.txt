cmake_minimum_required(VERSION 3.10)
project(simple_game)

# Cpp
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_PREFIX_PATH "/home/bcc/bfss21/local")


# Set the path to the SDL2 library and header files
set(SDL2_LIBRARY "/home/bcc/bfss21/local/lib/libSDL2.so")
set(SDL2_INCLUDE_DIR "/home/bcc/bfss21/local/include/SDL2")

set(SDL2_IMAGE_LIB "/home/bcc/bfss21/local/lib/libSDL2_image-2.0.so")
set(SDL2_IMAGE_INCLUDE_DIR "/home/bcc/bfss21/local/lib/include/SDL2")


#/local/lib/include/SDL2


# Not shitty dinf pcs
#set(SDL2_LIBRARY "/home/bcc/bfss21/local/lib/libSDL2.so")
#set(SDL2_INCLUDE_DIR "/usr/include/SDL2")



include_directories(${SDL2_INCLUDE_DIR})
include_directories(${SDL2_IMAGE_INCLUDE_DIR})


# Find the SDL2 library
find_package(SDL2 REQUIRED)

# Dependencies
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

find_library(SDL2_IMAGE_LIB SDL2_image /usr/local/lib)


# Add the executable target
add_executable(simple_game main.cpp libs/game.cpp libs/object.cpp)

# Add ??
target_include_directories(simple_game PRIVATE libs)


# Link the executable with the SDL2 library
target_link_libraries(simple_game ${SDL2_LIBRARY})
target_link_libraries(simple_game ${SDL2_IMAGE_LIB})
