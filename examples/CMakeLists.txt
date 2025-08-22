# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

set(ALL_EXAMPLES example)

# Example `identity_as_default_projection` need ranges support:
include(CheckCXXSymbolExists)
check_cxx_symbol_exists(__cpp_lib_ranges "ranges" HAS_RANGES)

message("Examples to be built: ${ALL_EXAMPLES}")

foreach(example ${ALL_EXAMPLES})
    add_executable(beman.cstring_view.examples.${example})
    target_sources(
        beman.cstring_view.examples.${example}
        PRIVATE ${example}.cpp
    )
    target_link_libraries(
        beman.cstring_view.examples.${example}
        PRIVATE beman::cstring_view
    )
endforeach()
