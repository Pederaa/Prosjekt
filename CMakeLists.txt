cmake_minimum_required(VERSION 3.21.0)
project(Laserturtle VERSION 0.1.0 LANGUAGES CXX)

find_package(SFML CONFIG REQUIRED COMPONENTS graphics window system)

add_executable(Laserturtle 
    src/backgroundGenerator.cpp 
    src/Bomb.cpp 
    src/eggsManager.cpp 
    src/explotionManager.cpp 
    src/gameRunner.cpp 
    src/laserCannon.cpp 
    src/LaserTurtleWindow.cpp 
    src/main.cpp 
    src/numBomb.cpp 
    src/readKeyInput.cpp 
    src/textBomb.cpp 
    src/typingScreen.cpp)

target_include_directories(Laserturtle PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(Laserturtle
    PRIVATE
        sfml-graphics
        sfml-window
        sfml-system
)

include(CTest)
enable_testing()