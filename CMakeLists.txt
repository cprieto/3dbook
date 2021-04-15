cmake_minimum_required (VERSION 3.19)
project (3dg)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
find_package(Catch2 REQUIRED)

add_library (vectors OBJECT vectors.cpp)

add_custom_target(test)
macro(run_test test_target)
    add_custom_target(${test_target}_runtest
            COMMAND ${test_target}
            DEPENDS ${test_target}
            WORKING_DIRECTORY "${CMAKE_BINARY_DIR}")
    add_dependencies(test ${test_target}_runtest)
endmacro()

list(APPEND test_sources
        tests_vectors.cpp)

add_executable(all_tests ${test_sources})
target_link_libraries(all_tests PRIVATE vectors Catch2::Catch2)
run_test(all_tests)
