set(HEADERS_ENGINE
    ${CMAKE_CURRENT_LIST_DIR}/include/AAudio.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/AEntity.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/AMissile.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/IEntity.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/IMovement.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/IWindow.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/Laser.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/Missile.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/Movement.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/Music.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/Particles.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/Scroller.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/Sound.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/Spacecraft.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/SpacecraftEntities.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/SpacecraftPlayer.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/Time.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/Window.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/World.hpp
    )

set(SRCS_ENGINE
    ${CMAKE_CURRENT_LIST_DIR}/src/Laser.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/Music.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/Particles.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/Scroller.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/Sound.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/Spacecraft.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/SpacecraftEntities.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/SpacecraftPlayer.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/Time.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/Window.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/World.cpp
    )

set(ENGINEHEADERS ${HEADERS_ENGINE})
add_library(GameEngine SHARED ${HEADERS_ENGINE} ${SRCS_ENGINE})
target_link_libraries(GameEngine CONAN_PKG::sfml)
set_target_properties(GameEngine PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Res/GameEngineLibrarie)
