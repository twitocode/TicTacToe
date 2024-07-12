cmake_minimum_required(VERSION 3.5.0)

set(CMAKE_CXX_COMPILER "C:/msys64/mingw64/bin/g++.exe")
set(CMAKE_C_COMPILER "C:/msys64/mingw64/bin/gcc.exe")

project(TicTacToe VERSION 0.1.0 LANGUAGES C CXX)

find_package(raylib 5.5 QUIET)

if (NOT RAYLIB_FOUND)
  include(FetchContent)
  FetchContent_Declare(
      raylib
      GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
      GIT_TAG "master"
      GIT_PROGRESS TRUE
  )
  FetchContent_GetProperties(raylib)

  if (NOT raylib_POPULATED)
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(raylib)
    add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
  endif()

  set(RAYLIB_FOUND TRUE)
endif()

add_executable(TicTacToe "./src/main.cpp")

set(CMAKE_C_STANDARD 11)
target_link_libraries(TicTacToe raylib)

target_sources(TicTacToe 
  PRIVATE
    src/Cell.cpp
  PUBLIC
    src/Cell.h
)

target_include_directories(TicTacToe PUBLIC include)
target_include_directories(TicTacToe PUBLIC src)

set_property(TARGET TicTacToe PROPERTY CXX_STANDARD_17)