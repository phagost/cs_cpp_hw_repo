cmake_minimum_required (VERSION 3.1)

project(hash)


#
# library with common functions for tests and exe
#
add_library(explib
        explib/crc32.cpp
        explib/crc32.h
        explib/sum32.cpp
        explib/sum32.h)

set_target_properties(explib PROPERTIES
                      CXX_STANDARD 17
                      CXX_STANDARD_REQUIRED YES
                      CXX_EXTENSIONS NO)

#
# project itself
#
add_executable(hash main.cpp)

set_target_properties(hash PROPERTIES
                      CXX_STANDARD 17
                      CXX_STANDARD_REQUIRED YES
                      CXX_EXTENSIONS NO)

add_dependencies(hash explib)
target_link_libraries(hash explib)
