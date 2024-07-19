cmake_minimum_required(VERSION 3.10)
project(lib)

set(LIB_SOURCES hmahl.c)
set(SOURCES hmah.c)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/include")
file(COPY "${CMAKE_SOURCE_DIR}/src/hmahl.h" DESTINATION "${CMAKE_BINARY_DIR}/include")

if(HMAH_DEBUG)
  add_definitions(-DHMAH_DEBUG)
endif()

if(HMAH_ENDL)
  add_definitions(-DHMAH_ENDL)
endif()

if(HMAH_SHARED)
  add_definitions(-DHMAH_SHARED)
  add_library(hmahl SHARED ${LIB_SOURCES})
elseif(HMAH_STATIC)
  add_definitions(-DHMAH_STATIC)
  add_library(hmahl STATIC ${LIB_SOURCES})
else()
  message(FATAL_ERROR "You must specify either HMAH_SHARED or HMAH_STATIC")
endif()

add_executable(hmah ${SOURCES})
target_link_libraries(hmah hmahl)
