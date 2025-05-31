cmake_minimum_required(VERSION 3.31)
project(tust_newspaper)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/opt/Qt/6.9.0/gcc_64")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(tust_newspaper main.cpp)
target_link_libraries(tust_newspaper
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

