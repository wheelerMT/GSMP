# Set the headers of the library
set(HEADER_LIST "include/GSMP_model_types.h" "include/GSMP_model.h")

# Make an automatic shared library
add_library(GSMP_API SHARED src/model.c ${HEADER_LIST})

# We need this directory, and users of our library will need it too
target_include_directories(GSMP_API PUBLIC include)

# All users of this library will need at least C17
target_compile_features(GSMP_API PUBLIC c_std_17)
