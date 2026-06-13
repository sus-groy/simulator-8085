cmake_minimum_required(VERSION 3.21)
project(simulator_8085 VERSION 0.1 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF) # Pure C11, no extensions

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Find the system's official threading library configurations
# May not be required in the future, we can remove it later if redundant
find_package(Threads REQUIRED)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.c")
add_executable(simulator_8085 ${SOURCES})

target_include_directories(simulator_8085 PRIVATE include)
target_link_libraries(simulator_8085 PRIVATE Threads::Threads)

# keeping this here regardless of whoever uses
if(MSVC)
    set(SANITIZERS /fsanitize=address)

    # Disable the RTC1 lib which CMake hooks to debug builds for ASan to work
    target_compile_options(simulator_8085 PRIVATE
        /W4 /WX /permissive-
        $<$<CONFIG:Debug>:/Od /Zi /RTC- ${SANITIZERS}>
        $<$<CONFIG:Release>:/O2>
    )

    # ASan requires incremental linking disabled too
    target_link_options(simulator_8085 PRIVATE
        $<$<CONFIG:Debug>:/INCREMENTAL:NO>
    )

    # And this apparently prevents MSVC generating an error if "unsafe" functions are used
    target_compile_definitions(simulator_8085 PRIVATE _CRT_SECURE_NO_WARNINGS)
else()
    set(SANITIZERS -fsanitize=address,undefined)

    target_compile_options(simulator_8085 PRIVATE
        -Wall -Wextra -Wpedantic -Werror
        $<$<CONFIG:Debug>:-Og -g3 ${SANITIZERS}>
        $<$<CONFIG:Release>:-O2>
    )

    target_link_options(simulator_8085 PRIVATE
        $<$<CONFIG:Debug>:${SANITIZERS}>
    )
endif()
