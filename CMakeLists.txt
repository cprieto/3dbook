cmake_minimum_required (VERSION 3.19)
project (3dg)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
find_package(Catch2 REQUIRED)
list(APPEND SOURCES
        src/vectors.cpp
        src/matrix.cpp)

add_library (vectors OBJECT ${SOURCES})

add_custom_target(test)
macro(run_test test_target)
    add_custom_target(${test_target}_runtest
            COMMAND ${test_target}
            DEPENDS ${test_target}
            WORKING_DIRECTORY "${CMAKE_BINARY_DIR}")
    add_dependencies(test ${test_target}_runtest)
endmacro()

include_directories(src)
list(APPEND test_sources
        tests/all.cpp
        tests/tests_vectors.cpp
        tests/tests_matrix.cpp)

add_executable(all_tests ${test_sources})
target_link_libraries(all_tests PRIVATE vectors Catch2::Catch2)
run_test(all_tests)
