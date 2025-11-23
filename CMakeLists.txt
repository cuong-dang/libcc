cmake_minimum_required(VERSION 3.28)
project(cc LANGUAGES C)
set(CMAKE_C_STANDARD 90)

add_library(${PROJECT_NAME})
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
