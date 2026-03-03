cmake_minimum_required(VERSION 3.16)

# Binary name
set(BINARY astdst)

# Project (C + C++)
project(${BINARY} LANGUAGES C CXX)

# Detect OS
if(WIN32)
    set(TARGET_OS "windows")
    set(BINARY "${BINARY}.exe")
elseif(APPLE)
    set(TARGET_OS "macos")
elseif(UNIX)
    set(TARGET_OS "linux")
endif()

message(STATUS "Compiling for: ${TARGET_OS}")

 
# Source root
set(SRC_ROOT ${CMAKE_SOURCE_DIR}/src)

 
# Collect all .c and .cpp files recursively
file(GLOB_RECURSE SOURCE_FILES
    ${SRC_ROOT}/*.c
    ${SRC_ROOT}/*.cpp
)

 
# Create executable
add_executable(${BINARY} ${SOURCE_FILES})

 
# Include directories
target_include_directories(${BINARY}
    PRIVATE
        ${SRC_ROOT}
)

 
# Language standards
set_target_properties(${BINARY} PROPERTIES
    C_STANDARD 11
    C_STANDARD_REQUIRED ON
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

 
# Compiler warnings and options
if(WIN32)
    target_compile_options(${BINARY}
        PRIVATE
            /W4
            /Od
            /Zi
    )
else()
    target_compile_options(${BINARY}
        PRIVATE
            -Wall
            -Wextra
            -g
            -O0
    )
endif()

 
# Find and link SDL3 properly
find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)

target_link_libraries(${BINARY}
    PRIVATE
        SDL3::SDL3
        SDL3_image::SDL3_image
)

if(UNIX AND NOT APPLE)
    target_link_libraries(${BINARY} PRIVATE m)
endif()

# Output binary in project root
set_target_properties(${BINARY}
    PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}
)
