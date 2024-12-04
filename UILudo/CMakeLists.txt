cmake_minimum_required(VERSION 3.10)

project(UILudo VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


if(APPLE)
    set(CMAKE_PREFIX_PATH "~/Qt/6.8.0/macos/lib/cmake/Qt6")
elseif(WIN32)
    if(CMAKE_SYSTEM_PROCESSOR MATCHES "ARM|aarch64")
        set(CMAKE_PREFIX_PATH "C:\\Qt\\6.8.0\\msvc2022_arm64\\lib\\cmake\\Qt6")
        set(WIN_DEPLOY "C:\\Qt\\6.8.0\\msvc2022_arm4\\bin\\windeployqt.exe")
        message("Found arm-based CPU.")
    else()
        set(CMAKE_PREFIX_PATH "C:\\Qt\\6.8.0\\msvc2022_64\\lib\\cmake\\Qt6")
        set(WIN_DEPLOY "C:\\Qt\\6.8.0\\msvc2022_64\\bin\\windeployqt.exe")
        message("Found amd64-based CPU.")
    endif()
else()
    set(CMAKE_PREFIX_PATH "~/Qt/6.8.0/linux/cmake/Qt6")
endif()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Gui Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Gui Widgets)

set(PROJECT_SOURCES
        main.cpp
        UILudo.cpp
        UILudo.h
        LudoGrid.cpp
        LudoGrid.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(UILudo
            MANUAL_FINALIZATION
            ${PROJECT_SOURCES}
            UILudo.qrc
            UILudo.ui
    )
else()
    add_executable(UILudo
            ${PROJECT_SOURCES}
    )
endif()
target_include_directories(UILudo PRIVATE ${CMAKE_SOURCE_DIR}/LibLudo)

add_dependencies(UILudo LibLudo)

target_link_libraries(UILudo PRIVATE
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Gui
        Qt${QT_VERSION_MAJOR}::Widgets
        LibLudo
)

if(APPLE OR WIN32)
    set_target_properties(UILudo PROPERTIES
            MACOSX_BUNDLE TRUE
            WIN32_EXECUTABLE TRUE
    )
endif()



include(GNUInstallDirs)
install(TARGETS UILudo
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(UILudo)
endif()

if(WIN32)
    add_custom_command(
            TARGET UILudo POST_BUILD
            COMMAND ${WIN_DEPLOY} $<TARGET_FILE:UILudo>
            COMMENT "Running windeployqt to deploy Qt dependencies"
    )
endif()