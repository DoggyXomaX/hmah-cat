cmake_minimum_required(VERSION 3.10)
project(tests)

function(add_test NAME)
  add_executable("${NAME}.bin" "${NAME}.c")
  target_include_directories("${NAME}.bin" PRIVATE ../src)
  target_link_libraries("${NAME}.bin" PRIVATE hmahl)
endfunction()

add_test(load_overflow)
add_test(just_cat)

file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/tests/")
file(COPY "${CMAKE_SOURCE_DIR}/tests/file1.txt" DESTINATION "${CMAKE_BINARY_DIR}/tests/")
file(COPY "${CMAKE_SOURCE_DIR}/tests/file2.txt" DESTINATION "${CMAKE_BINARY_DIR}/tests/")
