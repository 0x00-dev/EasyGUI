cmake_minimum_required(VERSION 3.13)

project(easyGUI)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER  "/usr/bin/g++")

set(SFML_INCLUDE_DIR "/home/strannyi_tip/lib/SFML-2.5.1/include")
set(SFML_LIBRARY_DIR "/home/strannyi_tip/lib/SFML-2.5.1/lib")
set(SFML_DIR "/home/strannyi_tip/lib/SFML-2.5.1/lib/cmake/SFML")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)
include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${PROJECT_SOURCE_DIR}/src")

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()

add_executable(${PROJECT_NAME} main.cpp include/Window/ModalWindow.hpp src/Window/ModalWindow.cpp include/Interface/Containable.hpp include/Interface/Eventable.hpp include/Interface/Displayable.hpp include/Core/Definitions.hpp include/Core/Messenger.hpp src/Core/Messenger.cpp include/Controls/Button.hpp src/Controls/Button.cpp include/Controls/Input.hpp src/Controls/Input.cpp)
target_link_libraries (${PROJECT_NAME} sfml-network sfml-graphics sfml-window sfml-system)