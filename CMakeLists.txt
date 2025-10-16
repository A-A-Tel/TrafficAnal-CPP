cmake_minimum_required(VERSION 4.0)
project(TrafficAnal_CPP)

include_directories(inc/)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/out/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/out/bin)

add_executable(main src/main.cpp
        src/traffic_anal/requests.cpp
)

find_package(Boost REQUIRED REQUIRED COMPONENTS json)

find_package(date REQUIRED)

target_link_libraries(main PRIVATE date-tz)
target_link_libraries(main PRIVATE Boost::json)
target_link_libraries(main PRIVATE ${CMAKE_SOURCE_DIR}/lib/liblogger.a)