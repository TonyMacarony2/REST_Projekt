
cmake_minimum_required(VERSION 3.24.2)
project(REST_Projekt)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_TOOLCHAIN_FILE "C:/Users/tony/.vcpkg-clion/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

add_executable(REST_Projekt main.cpp
        CatAscii.h
        CatAscii.cpp
        FlowerAscii.h
        FlowerAscii.cpp
        RandomNumber.h
        RandomNumber.cpp
        ApiHandler.h
        ApiHandler.cpp)

find_package(CURL REQUIRED)

include_directories(${CURL_INCLUDE_DIR})

target_link_libraries(REST_Projekt CURL::libcurl)