# cppCMakeProjectSetup

## Project Definition

We have provided a basic skeleton of the files and directories that are required to build a C++ project using CMake and Google Test for testing on macOS.

## Project Structure

The project is organized as follows:

```
/cppCMakeProjectSetup
    CMakeLists.txt
    /src
        my_header.cpp
        main.cpp
    /include
        my_header.h
    /tests
        CMakeLists.txt
        test_my_code.cpp
```
      
## Building the Project

To build the project using CMake, follow these steps in the Command Line:

1. Create a build directory from the `/cppCMakeProjectSetup` directory and navigate into it:

    ```bash
    mkdir build && cd build
    ```

2. Generate the build files using CMake:

    ```bash
    cmake ..
    ```

3. Build the project:

    ```bash
    make
    ```

Note that both `cmake ..` and `make` should be executed within the `build` directory to ensure that build files are created within this directory.

## Running the Project

1. **Run Main Executable Directly**

    To run the main executable after building the project, navigate to the `cppCMakeProjectSetup` directory, and execute:

    ```bash
    ./main_program
    ```

## Running the Tests

### Option 1: Run Tests with `ctest`

To run the tests using the `ctest` command, follow these steps:

1. Ensure you are in the `/build/tests` directory:

    ```bash
    cd build/tests
    ```

2. Execute the `ctest` command:

    ```bash
    ctest
    ```

   Note that the `ctest` command must be run from the `/build/tests` directory to work correctly.

### Option 2: Run the Test Executable Directly

Alternatively, you can run the test executable directly from the `cppCMakeProjectSetup` directory after building the project. Simply execute:

    ```bash
    ./test_my_code
    ```
    
## Additional Notes

1. **Executable Output Directory**

   We have configured the top-level `CMakeLists.txt` file to output the executables `main_program` and `test_my_code` at the `cppCMakeProjectSetup` directory level.
   This is controlled by the following setting:

    ```cmake
    # Set output directory for executables
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
    ```

   If you remove this configuration, `main_program` will instead be built in the `build` directory, and `test_my_code` will be built in `/build/tests`.

3. **Header Files**

   Header files (`.h`) are placed in a separate directory called `include`. CMake is instructed to find these header files using:

    ```cmake
    # Add include directory for headers
    include_directories(${CMAKE_SOURCE_DIR}/include)
    ```

4. **Google Test Suite**

   The Google Test framework is included in the `/tests/CMakeLists.txt` file, which is a standard practice for CMake projects.

   ```cmake
   include(FetchContent)

   # Fetch the latest stable release of Google Test
   FetchContent_Declare(
     googletest
     URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip  # You can use the latest stable version here
   )
    
   # Make Google Test available
   FetchContent_MakeAvailable(googletest)
   ```
   
5. **Cleaning the Build**

   To clean up the build and remove generated files, you can execute the following command:

    ```bash
    rm -rf build
    ```

   This command removes the entire `build` directory, including all generated files and directories.
   If you have specific executables that need to be removed from the `cppCMakeProjectSetup` directory, you can also run:

    ```bash
    rm -f my_program test_my_code
    ```

