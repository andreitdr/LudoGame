cmake_minimum_required(VERSION 3.10)

project(LibLudo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_library(LibLudo STATIC
        gameManagement/decisionMaker/DecisionMaker.cpp
        gameManagement/decisionMaker/DecisionMaker.h
        model/dice/Dice.cpp
        model/dice/Dice.h
        gameManagement/game/Game.cpp
        gameManagement/game/Game.h
        observer/Observable.cpp
        observer/IObserver.h
        observer/Observable.h
        model/pawn/Pawn.cpp
        model/pawn/Pawn.h
        model/player/Player.cpp
        model/player/Player.h
        model/playerColor/PlayerColor.h
)

target_include_directories(LibLudo PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

message(STATUS "Configuration complete.")