cmake_minimum_required(VERSION 3.26)
project(sem_pr)

set(CMAKE_CXX_STANDARD 17)

include_directories(lib/nlochman/include)

add_executable(sem_pr main.cpp
        src/core/model/figure.h
        src/core/model/point.h
        src/core/model/circle.h
        src/core/model/parallelogram.h
        src/core/model/rectangle.h
        src/core/dao/filereader.h
        src/core/utils/vector.h
        src/core/model/triangle.h)
