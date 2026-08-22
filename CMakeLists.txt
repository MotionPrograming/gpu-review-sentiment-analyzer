cmake_minimum_required(VERSION 3.20)

project(GPUParquetReader
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Arrow REQUIRED)
find_package(Parquet REQUIRED)

add_executable(parquet_reader
    src/main.cpp
)

target_link_libraries(parquet_reader
    PRIVATE
        Arrow::arrow_shared
        Parquet::parquet_shared
)
