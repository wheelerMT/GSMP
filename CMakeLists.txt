# Works with 3.15 and tested through 3.30
cmake_minimum_required(VERSION 3.15...3.30)

# Project name and a few useful settings. Other commands can pick up the results
project(
        GSMP
        VERSION 0.1
        DESCRIPTION "A Generic Simulation & Modelling Platform"
        LANGUAGES C CXX)

# Only do these if this is the main project, and not if it is included through add_subdirectory
if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

    # Let's ensure -std=c++xx instead of -std=g++xx
    set(CMAKE_CXX_EXTENSIONS OFF)

    # Use C++20
    set(CMAKE_CXX_STANDARD 20)

    # Let's nicely support folders in IDEs
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)

    # Testing only available if this is the main app
    # Note this needs to be done in the main CMakeLists
    # since it calls enable_testing, which must be in the
    # main CMakeLists.
    include(CTest)

    # Docs only available if this is the main app
    find_package(Doxygen)
    if (Doxygen_FOUND)
        add_subdirectory(docs)
    else ()
        message(STATUS "Doxygen not found, not building docs")
    endif ()
endif ()

# FetchContent added in CMake 3.11, downloads during the configure step
include(FetchContent)

# The compiled library code is here
add_subdirectory(src/models/c)
add_subdirectory(src/models/cpp)

# Executable code
add_subdirectory(src/cli)

# Testing only available if this is the main app
# Emergency override MODERN_CMAKE_BUILD_TESTING provided as well
#if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR MODERN_CMAKE_BUILD_TESTING)
#        AND BUILD_TESTING)
#    add_subdirectory(test)
#endif()
