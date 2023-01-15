cmake_minimum_required(VERSION 3.23)
project(AP1_Ex4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(AP1_Ex4
        Main.cpp
        CanberraDistance.h
        CanberraDistance.cpp
        ChebyshevDistance.h
        ChebyshevDistance.cpp
        Distance.h
        Distance.cpp
        EuclidianDistance.h
        EuclidianDistance.cpp
        IfstreamToMap.h
        IfstreamToMap.cpp
        KNN.h
        KNN.cpp
        ManhattanDistance.h
        ManhattanDistance.cpp
        MinkowskiDistance.cpp
        MinkowskiDistance.h
        StrToVector.h
        StrToVector.cpp
        Client.cpp
        Client.cpp
        Server.cpp
        DefaultIO.cpp
        DefaultIO.h
        StandardIO.cpp
        StandardIO.h)
