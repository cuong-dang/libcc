# binaries
set(STD_TESTS
  assert
  ctype
)

# link & add
foreach (t ${STD_TESTS})
  add_executable(std_test_${t} test_${t}.c)
  target_link_libraries(std_test_${t} PRIVATE cc)
  target_include_directories(std_test_${t}
    PRIVATE
      ${CMAKE_SOURCE_DIR}/include
      ${CMAKE_SOURCE_DIR}/tests/include)
  add_test(NAME std_${t} COMMAND std_test_${t})
endforeach ()
