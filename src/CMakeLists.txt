cmake_minimum_required(VERSION 3.10)
project(lib)

set(LIB_SOURCES hmahl.c)
set(SOURCES hmah.c)

if(HMAH_DEBUG)
  add_definitions(-DHMAH_DEBUG)
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

file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/include")
file(COPY "${CMAKE_SOURCE_DIR}/src/hmahl.h" DESTINATION "${CMAKE_BINARY_DIR}/include")