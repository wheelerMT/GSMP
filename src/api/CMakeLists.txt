# Make an automatic shared library
add_library(GSMP_API SHARED ${CMAKE_CURRENT_SOURCE_DIR}/src/model.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/variable_manager.cpp)

# We need this directory, and users of our library will need it too
target_include_directories(GSMP_API PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# All users of this library will need at least C17
target_compile_features(GSMP_API PUBLIC c_std_17)
