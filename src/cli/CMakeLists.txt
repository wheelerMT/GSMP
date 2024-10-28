add_executable(GSMP cli.cpp)
target_compile_features(GSMP PRIVATE cxx_std_17)

target_link_libraries(GSMP PRIVATE GSMP_CPP GSMP_C)