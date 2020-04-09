project(r-type_server)
cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)

find_package(Threads)

if (UNIX)
    set(CMAKE_CXX_FLAGS "-W -Wall -Wextra -Werror")
endif (UNIX)

set(DIRINCLUDE
    include
    ../Client/include
)

include_directories(${DIRINCLUDE})

set(SRCSERVER
    main.cpp
    src/Client.cpp
    src/ClientManager.cpp
    src/PacketManager.cpp
    src/Player.cpp
    src/RingBuffer.cpp
    src/Room.cpp
    src/RoomManager.cpp
    src/Server.cpp
    ../Client/src/Packet.cpp
    ../Client/src/UnixSocket.cpp
    ../Client/src/WindowsSocket.cpp
    )

add_executable(r-type_server ${SRCSERVER})

target_link_libraries(r-type_server ${CMAKE_THREADS_LIBS_INIT})