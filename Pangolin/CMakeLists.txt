cmake_minimum_required(VERSION 2.8)
project(MyPanglointest)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Find Pangolin package
find_package(Pangolin REQUIRED)

# Add executable and specify source files
add_executable(MyApp test_1.cpp)

# Link against Pangolin
target_link_libraries(MyApp ${Pangolin_LIBRARIES})

# Add include directories
target_include_directories(MyApp PRIVATE ${Pangolin_INCLUDE_DIRS})