cmake_minimum_required(VERSION 3.16)
project(3DCube)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_OSX_ARCHITECTURES arm64)
add_definitions(-DGL_SILENCE_DEPRECATION)

# Include directories
include_directories(
        ${CMAKE_SOURCE_DIR}/dep/GLFW/include
        ${CMAKE_SOURCE_DIR}/dep/GLEW/include
        ${CMAKE_SOURCE_DIR}/vendor/imgui
        ${CMAKE_SOURCE_DIR}/vendor
        ${CMAKE_SOURCE_DIR}/vendor/glm
        ${CMAKE_SOURCE_DIR}/vendor/stb_image
)

# Source files
file(GLOB SRC_FILES
        ${CMAKE_SOURCE_DIR}/source/*.cpp
        #${CMAKE_SOURCE_DIR}/src/Tests/*.cpp
        #${CMAKE_SOURCE_DIR}/Vendor/imgui/*.cpp
)

# Create the executable
add_executable(3DCube
        ${SRC_FILES}
        source/Camera.cpp
        source/Camera.cpp
        source/Camera.h
        source/Texture.cpp
        source/Texture.h
)

# Link directories
link_directories(
        ${CMAKE_SOURCE_DIR}/Dep/GLFW/lib
        ${CMAKE_SOURCE_DIR}/Dep/GLEW/lib
)

# Link libraries
target_link_libraries(3DCube
        ${CMAKE_SOURCE_DIR}/Dep/GLFW/lib/libglfw3.a
        ${CMAKE_SOURCE_DIR}/Dep/GLEW/lib/libGLEW.a
        "-framework OpenGL"
        "-framework Cocoa"
        "-framework IOKit"
        "-framework CoreVideo"
)
