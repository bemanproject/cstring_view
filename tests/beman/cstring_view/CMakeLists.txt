# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

find_package(GTest REQUIRED)

add_executable(beman.cstring_view.tests.identity)
target_sources(beman.cstring_view.tests.identity PRIVATE cstring_view.test.cpp)
target_link_libraries(
    beman.cstring_view.tests.identity
    PRIVATE beman::cstring_view GTest::gtest GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(beman.cstring_view.tests.identity)
