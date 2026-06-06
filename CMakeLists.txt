cmake_minimum_required(VERSION 3.14)
project(simulator_8085 VERSION 1.1 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB SOURCES CONFIGURE_DEPENDS "src/*.c")
add_executable(simulator_8085 ${SOURCES})

target_include_directories(simulator_8085 PRIVATE include)
if(MSVC)
    # MSVC equivalent flags: 
    # /W4 (High warning level), /WX (Treat warnings as errors)
    target_compile_options(simulator_8085 PRIVATE /W4 /WX)
else()
    # Keeps GCC/Clang flags for Linux/macOS
    target_compile_options(simulator_8085 PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()