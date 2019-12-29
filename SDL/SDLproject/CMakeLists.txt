cmake_minimum_required(VERSION 3.8)
project(CPROG_Inlupp)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")
find_package(SDL2 REQUIRED)

find_package(SDL2_ttf REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)


include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR} ${SDL2_MIXER_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 11)

file(GLOB SOURCES *.cpp *.h)
##### TA INTE BORT
##file(GLOB SOURCES src/*.cpp src/*.h implementation/*.cpp implementation/*.h)
#### TA INTE BORT



#set(SOURCE_FILES main.cpp)
#### TA INTE BORT
#add_executable(Spel ${SOURCES} src/System.cpp src/System.h src/Sprite.cpp src/Sprite.h src/MovingSprite.cpp src/MovingSprite.h)
add_executable(CPROG_Inlupp ${SOURCES} Engine.h Engine.cpp Main.cpp GameObject.cpp GameObject.h  Player.cpp Player.h Invader.cpp Invader.h Bullet.cpp Bullet.h Session.cpp Session.h Collider.cpp Collider.h)
#### TA INTE BORT

target_link_libraries(CPROG_Inlupp ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_TTF_LIBRARIES} ${SDL2_MIXER_LIBRARIES})