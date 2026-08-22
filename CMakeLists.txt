cmake_minimum_required(VERSION 3.16)

project(cpp_parquet_test)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Arrow REQUIRED)
find_package(Parquet REQUIRED)

add_executable(parquet_test
    src/main.cpp
)

target_link_libraries(parquet_test
    PRIVATE
    Arrow::arrow_shared
    Parquet::parquet_shared
)