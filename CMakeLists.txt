# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

cmake_minimum_required(VERSION 3.25)

set(CMAKE_CXX_STANDARD 23)

project(
    beman.cstring_view # CMake Project Name, which is also the name of the top-level
    # targets (e.g., library, executable, etc.).
    DESCRIPTION "cstring_view, a null-terminated string view"
    LANGUAGES CXX
    VERSION 0.0.1
)

# [CMAKE.SKIP_TESTS]
option(
    BEMAN_CSTRING_VIEW_BUILD_TESTS
    "Enable building tests and test infrastructure. Default: ${PROJECT_IS_TOP_LEVEL}. Values: { ON, OFF }."
    ${PROJECT_IS_TOP_LEVEL}
)

# [CMAKE.SKIP_EXAMPLES]
option(
    BEMAN_CSTRING_VIEW_BUILD_EXAMPLES
    "Enable building examples. Default: ${PROJECT_IS_TOP_LEVEL}. Values: { ON, OFF }."
    ${PROJECT_IS_TOP_LEVEL}
)

option(
    BEMAN_CSTRING_VIEW_INSTALL_CONFIG_FILE_PACKAGE
    "Enable creating and installing a CMake config-file package. Default: ${PROJECT_IS_TOP_LEVEL}. Values: { ON, OFF }."
    ${PROJECT_IS_TOP_LEVEL}
)

option(
    ENABLE_TEST_COVERAGE
    "Compile with test-coverage flags"
    ${PROJECT_IS_TOP_LEVEL}
)
if(UNIX AND ENABLE_TEST_COVERAGE AND CMAKE_BUILD_TYPE STREQUAL Debug)
    message(WARNING "ENABLE_TEST_COVERAGE is set!")
    add_compile_options(-O0 -g -fprofile-arcs -ftest-coverage)
    add_link_options(-fprofile-arcs -ftest-coverage)
    # TODO(CK): add_compile_definitions(TARGET_CODE_COVERAGE)
endif()

include(CTest)

add_subdirectory(src/beman/cstring_view)

if(BEMAN_CSTRING_VIEW_BUILD_TESTS)
    add_subdirectory(tests/beman/cstring_view)
endif()

if(BEMAN_CSTRING_VIEW_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()
