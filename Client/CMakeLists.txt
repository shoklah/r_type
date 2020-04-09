project(r-type_client)
cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)

if (UNIX)
    set(CMAKE_CXX_FLAGS "-W -Wall -Wextra -Werror")
endif (UNIX)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

set(DIRINCLUDE
    include
    ../GameEngine/include
)

include_directories(${DIRINCLUDE})

set(SRCCLIENT
    ../GameEngine/src/Laser.cpp
    ../GameEngine/src/Music.cpp
    ../GameEngine/src/Particles.cpp
    ../GameEngine/src/Scroller.cpp
    ../GameEngine/src/Sound.cpp
    ../GameEngine/src/Spacecraft.cpp
    ../GameEngine/src/SpacecraftEntities.cpp
    ../GameEngine/src/SpacecraftPlayer.cpp
    ../GameEngine/src/Time.cpp
    ../GameEngine/src/Window.cpp
    ../GameEngine/src/World.cpp
    src/main.cpp
    src/Action.cpp
    src/EntityContainer.cpp
    src/Game.cpp
    src/MsgHandler.cpp
    src/Packet.cpp
    src/Select.cpp
    src/UnixSocket.cpp
    src/WindowsSocket.cpp
    )

add_executable(r-type_client ${SRCCLIENT})

target_link_libraries(r-type_client CONAN_PKG::sfml)