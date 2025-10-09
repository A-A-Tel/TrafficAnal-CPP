cmake_minimum_required(VERSION 4.0)
project(TrafficAnal_CPP)

include_directories(inc/)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/out/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${PROJECT_SOURCE_DIR}/out/bin)

add_executable(main src/main.cpp)
