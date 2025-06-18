# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

include(GNUInstallDirs)

add_library(beman.cstring_view)
add_library(beman::cstring_view ALIAS beman.cstring_view)

target_sources(beman.cstring_view PRIVATE identity.cpp)

target_sources(
    beman.cstring_view
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/../../../include
        FILES
            ${CMAKE_CURRENT_SOURCE_DIR}/../../../include/beman/cstring_view/identity.hpp
)

set_target_properties(
    beman.cstring_view
    PROPERTIES VERIFY_INTERFACE_HEADER_SETS ON EXPORT_NAME cstring_view
)

install(
    TARGETS beman.cstring_view COMPONENT beman.cstring_view
    EXPORT beman.cstring_view
    DESTINATION
    ${CMAKE_INSTALL_LIBDIR}$<$<CONFIG:Debug>:/debug>
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}$<$<CONFIG:Debug>:/debug>
    FILE_SET HEADERS DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

if(BEMAN_CSTRING_VIEW_INSTALL_CONFIG_FILE_PACKAGE)
    include(CMakePackageConfigHelpers)

    configure_package_config_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/beman.cstring_view-config.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/beman.cstring_view-config.cmake"
        INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/beman.cstring_view"
        PATH_VARS PROJECT_NAME PROJECT_VERSION
    )

    write_basic_package_version_file(
        "${CMAKE_CURRENT_BINARY_DIR}/beman.cstring_view-config-version.cmake"
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY ExactVersion
    )

    install(
        FILES
            "${CMAKE_CURRENT_BINARY_DIR}/beman.cstring_view-config.cmake"
            "${CMAKE_CURRENT_BINARY_DIR}/beman.cstring_view-config-version.cmake"
        DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/beman.cstring_view"
        COMPONENT beman.cstring_view
    )

    install(
        EXPORT beman.cstring_view
        DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/beman.cstring_view"
        NAMESPACE beman::
        FILE beman.cstring_view-targets.cmake
        COMPONENT beman.cstring_view
    )
endif()
