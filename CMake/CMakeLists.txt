cmake_minimum_required(VERSION 3.22)
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/)
project(Functions)
set(exe_name fun)
# This is how you make an executable
add_executable(${exe_name} 
  main.cpp
  Functions.cpp
  Functions.hpp
  )
install(TARGETS ${exe_name} DESTINATION "dist")