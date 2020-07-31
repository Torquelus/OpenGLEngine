# Project Details
cmake_minimum_required(VERSION 3.8)
project("OpenGLEngineTest")

# C++ Standard
set (CMAKE_CXX_STANDARD 17)

# Define Debug Flags
set(DEBUG_FLAGS "-g")

# Add Debug Flags
add_definitions(${DEBUG_FLAGS})

# Add source files
file(GLOB_RECURSE SOURCE_FILES ${CMAKE_SOURCE_DIR}/src/*.c ${CMAKE_SOURCE_DIR}/src/*.cpp)

# Add header files
file(GLOB_RECURSE HEADER_FILES ${CMAKE_SOURCE_DIR}/src/*.h ${CMAKE_SOURCE_DIR}/src/*.hpp)

# Add vendor files
file(GLOB_RECURSE VENDOR_FILES ${CMAKE_SOURCE_DIR}/src/vendor/*/*.c ${CMAKE_SOURCE_DIR}/src/vendor/*/*.cpp)

# Copy shaders
file(COPY ${CMAKE_SOURCE_DIR}/res/shaders DESTINATION ${CMAKE_BINARY_DIR}/shaders)

# Add executables
add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES} ${VENDOR_FILES})

# Include folders
include_directories(${CMAKE_SOURCE_DIR}/src/Vendor)

# Include OpenGL and GLFW
set(LIBS "-lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl")
target_link_libraries(${PROJECT_NAME} ${LIBS})