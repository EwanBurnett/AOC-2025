project("AoC-01")

add_executable(${PROJECT_NAME} 
    main.cpp
 "aoc-01.h" "aoc-01.cpp")

enable_testing()
add_executable("${PROJECT_NAME}-Tests"
    tests.cpp
 "aoc-01.h"
 "aoc-01.cpp")

target_link_libraries("${PROJECT_NAME}-Tests" PUBLIC
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}-Tests)