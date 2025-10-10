# sources
file(GLOB TEST_SOURCES CONFIGURE_DEPENDS
        ${CMAKE_CURRENT_LIST_DIR}/*/*.c
)

# runner
add_executable(cc_tests ${TEST_SOURCES})
target_link_libraries(cc_tests PRIVATE cc)
target_include_directories(cc_tests PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)

# Register with CTest
add_test(NAME cc_tests COMMAND cc_tests)
