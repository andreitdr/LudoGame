cmake_minimum_required(VERSION 3.10)

project(LibLudo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_library(LibLudo STATIC
        DecisionMaker.cpp
        DecisionMaker.h
        Dice.cpp
        Dice.h
        Game.cpp
        Game.h
        Observable.cpp
        IObserver.h
        Observable.h
        Pawn.cpp
        Pawn.h
        Player.cpp
        Player.h
        PlayerColor.h
)

target_include_directories(LibLudo PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

message(STATUS "Configuration complete.")