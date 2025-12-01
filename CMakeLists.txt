# CMake
cmake_minimum_required(VERSION 3.28)
project(cc LANGUAGES C)

# Lib type
option(CC_SHARED "Enable shared library (dynamic linking)" OFF)
set(CC_LIB_TYPE STATIC)
if(CC_SHARED)
  set(CC_LIB_TYPE SHARED)
endif()

# Properties
add_library(${PROJECT_NAME} ${CC_LIB_TYPE})
target_compile_features(${PROJECT_NAME} PRIVATE c_std_90)
set_target_properties(
  ${PROJECT_NAME}
  PROPERTIES
  C_STANDARD_REQUIRED ON
  C_EXTENSIONS OFF
)

# Sources
target_sources(${PROJECT_NAME} PRIVATE
  src/std/assert.c
  src/std/ctype_is.c
  src/std/ctype_tolower.c
  src/std/ctype_toupper.c
  src/std/errno.c
)
target_include_directories(${PROJECT_NAME} PUBLIC
  $<BUILD_LOCAL_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
