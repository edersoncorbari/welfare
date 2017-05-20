# file CMakeLists.txt
 
# Set minimum build version.
cmake_minimum_required(VERSION 2.6)
 
# Set name project.
project(lib)

# Include path source dir. 
include_directories(${lib_SOURCE_DIR})

# Set name shared lib.
add_library(welfare SHARED welfare/bmi.hpp welfare/bmi.cxx)

# Set name static lib.
#add_library(welfare src/bmi.cxx)

# Set executables codes..
add_executable(bmi_test test/bmi_test.cxx)
add_executable(welfare_compute_bmi tools/welfare_compute_bmi/welfare_compute_bmi.cxx)

# Set lib.
#set($LIBS welfare)

# Link the executable with the lib.
target_link_libraries(bmi_test welfare)
target_link_libraries(welfare_compute_bmi welfare)

