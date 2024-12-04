cmake_minimum_required(VERSION 3.10)
project(LudoTests)

set(CMAKE_CXX_STANDARD 17)
set(FETCHCONTENT_QUIET FALSE)
set(BUILD_SHARED_LIBS OFF)

# This option works only for Windows systems
# This is not tested on Windows arm systems
if(WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")
endif(WIN32)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.15.2
        GIT_PROGRESS TRUE
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)




add_executable(LudoTests 
        main.cpp
        DecisionMakerTests.cpp
        DiceTests.cpp
        GameTests.cpp
        PawnTests.cpp
        PlayerTests.cpp
)

target_include_directories(LudoTests PRIVATE ${CMAKE_SOURCE_DIR}/LibLudo)

add_dependencies(LudoTests LibLudo)

target_link_libraries(LudoTests GTest::gmock  GTest::gtest GTest::gmock_main GTest::gtest_main LibLudo)

enable_testing()