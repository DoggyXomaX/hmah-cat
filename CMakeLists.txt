cmake_minimum_required(VERSION 3.10)
project(hmah)

option(HMAH_SHARED "Build as a shared library" ON)
option(HMAH_STATIC "Build as a static library" OFF)
option(HMAH_TESTS "Build tests" OFF)
option(HMAH_DEBUG "Debug hmah lib errors" OFF)

add_subdirectory(src)

if(HMAH_TESTS)
  add_subdirectory(tests)
endif()