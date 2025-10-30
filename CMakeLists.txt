cmake_minimum_required(VERSION 3.10)
project(cc VERSION 0.0.1 LANGUAGES C)
set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_C_EXTENSIONS OFF)

# build output
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# sources
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
)
add_library(cc_objs OBJECT ${SOURCES})
target_include_directories(cc_objs
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
  PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

# shared lib
add_library(cc SHARED $<TARGET_OBJECTS:cc_objs>)
set_target_properties(cc PROPERTIES
  VERSION   ${PROJECT_VERSION}
  SOVERSION ${PROJECT_VERSION_MAJOR}
)

# static lib
add_library(cc_static STATIC $<TARGET_OBJECTS:cc_objs>)
set_target_properties(cc_static PROPERTIES OUTPUT_NAME cc)


# install
include(GNUInstallDirs)
install(TARGETS cc cc_static
  EXPORT ccTargets
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# testing
include(CTest)
if (BUILD_TESTING)
  add_subdirectory(tests)
endif()
