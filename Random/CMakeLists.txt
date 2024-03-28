cmake_minimum_required(VERSION 3.22)
project(Random LANGUAGES CXX)
set(CMAKE_INSTALL_PREFIX \${CMAKE_BINARY_DIR}/dist)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(POLICY CMP0135)
  cmake_policy(SET CMP0135 NEW)
endif()
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
  )
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

add_executable(Random
  Random.cpp
  Random.hpp
  RandomTests.cpp
  )
target_link_libraries(Random GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(Random)
install(TARGETS Random DESTINATION .)