cmake_minimum_required(VERSION 3.10.0)
project(Laserturtle VERSION 0.1.0 LANGUAGES C CXX)

find_package(SFML COMPONENTS graphics window system REQUIRED)

add_executable(Laserturtle backgroundGenerator.cpp Bomb.cpp eggsManager.cpp explotionManager.cpp gameRunner.cpp laserCannon.cpp LaserTurtleWindow.cpp main.cpp numBomb.cpp readKeyInput.cpp textBomb.cpp typingScreen.cpp)

target_include_directories(Laserturtle PRIVATE${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(Laserturtle
    PRIVATE
        sfml-graphics
        sfml-window
        sfml-system
)

include(CTest)
enable_testing()

