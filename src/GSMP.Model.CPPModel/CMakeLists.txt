set(HEADER_LIST "include/model.h")

# Make an automatic library - will be static or dynamic based on user setting
add_library(GSMP_CPP src/model.cpp ${HEADER_LIST})

# We need this directory, and users of our library will need it too
target_include_directories(GSMP_CPP PUBLIC include)

# All users of this library will need at least C++17
target_compile_features(GSMP_CPP PUBLIC cxx_std_17)
