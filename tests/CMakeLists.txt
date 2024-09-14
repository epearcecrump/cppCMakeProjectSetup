# CMakeLists.txt in the tests directory
enable_testing()

# Include FetchContent to download and build Google Test
include(FetchContent)

# Fetch the latest stable release of Google Test
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip  # You can use the latest stable version here
)

# Make Google Test available
FetchContent_MakeAvailable(googletest)

# Add the test executable
add_executable(test_my_code test_my_code.cpp ${CMAKE_SOURCE_DIR}/src/my_header.cpp)

# Link test executable with Google Test and the code to be tested
target_link_libraries(test_my_code gtest gtest_main)

# Add tests to CTest
add_test(NAME MyTest COMMAND test_my_code)
