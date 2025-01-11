# Define a target for the modular tests
add_executable(unit_test "gsmp/model_variable_test.cpp" "gsmp/variable_manager_test.cpp" "gsmp/model_test.cpp")

# Link the test target with Google Test and production library
target_link_libraries(unit_test PRIVATE gtest gtest_main GSMP_CPP)

# Register in Google Test, and add to CTest
gtest_discover_tests(unit_test)