cmake_minimum_required(VERSION 3.16)

include(FetchContent)

project(game_engine)

set(CMAKE_CXX_STANDARD 20)

set(SFML_VERSION "2.5.1")

FetchContent_Declare(
    sfml
    GIT_REPOSITORY "https://github.com/SFML/SFML.git"
    GIT_TAG        "${SFML_VERSION}"
)

FetchContent_GetProperties(sfml)
if(NOT sfml_POPULATED)
    FetchContent_Populate(sfml)
    add_subdirectory(${sfml_SOURCE_DIR} ${sfml_BINARY_DIR})
endif()

if(WIN32)
    SET(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "C:/win32libs/boost")
    SET(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "C:/win32libs/boost/lib")
endif(WIN32)

find_package(Boost 1.69.0)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  ADD_DEFINITIONS( "-DHAS_BOOST" )
endif()

set(SOURCE
    ./src/main.cpp
)

include_directories(
    ./include/
)

if(WIN32)
    if(EXISTS "build")
        if(EXISTS "build/x64-Debug/_deps/sfml-build/lib/sfml-graphics-d-2.dll")
            file(COPY "build/x64-Debug/_deps/sfml-build/lib/sfml-graphics-d-2.dll"
                DESTINATION ${BINARY_DIR}/)
        endif()
        if(EXISTS "build/x64-Debug/_deps/sfml-build/lib/sfml-network-d-2.dll")
            file(COPY "build/x64-Debug/_deps/sfml-build/lib/sfml-network-d-2.dll"
                DESTINATION ${BINARY_DIR}/)
        endif()
        if(EXISTS "build/x64-Debug/_deps/sfml-build/lib/sfml-system-d-2.dll")
            file(COPY "build/x64-Debug/_deps/sfml-build/lib/sfml-system-d-2.dll"
                DESTINATION ${BINARY_DIR}/)
        endif()
        if(EXISTS "build/x64-Debug/_deps/sfml-build/lib/sfml-window-d-2.dll")
            file(COPY "build/x64-Debug/_deps/sfml-build/lib/sfml-window-d-2.dll"
                DESTINATION ${BINARY_DIR}/)
        endif()
    else()
        if(EXISTS "out/build/x64-Debug/_deps/sfml-build/lib/sfml-graphics-d-2.dll")
            file(COPY "out/build/x64-Debug/_deps/sfml-build/lib/sfml-graphics-d-2.dll"
                DESTINATION ${BINARY_DIR}/)
        endif()
        if(EXISTS "out/build/x64-Debug/_deps/sfml-build/lib/sfml-network-d-2.dll")
            file(COPY "out/build/x64-Debug/_deps/sfml-build/lib/sfml-network-d-2.dll"
                DESTINATION ${BINARY_DIR}/)
        endif()
        if(EXISTS "out/build/x64-Debug/_deps/sfml-build/lib/sfml-system-d-2.dll")
            file(COPY "out/build/x64-Debug/_deps/sfml-build/lib/sfml-system-d-2.dll"
                DESTINATION ${BINARY_DIR}/)
        endif()
        if(EXISTS "out/build/x64-Debug/_deps/sfml-build/lib/sfml-window-d-2.dll")
            file(COPY "out/build/x64-Debug/_deps/sfml-build/lib/sfml-window-d-2.dll"
                DESTINATION ${BINARY_DIR}/)
        endif()
    endif()
endif(WIN32)

add_executable(game_engine
    ${SOURCE}
)

target_link_libraries(game_engine
    PRIVATE
        sfml-window
        sfml-audio
        sfml-graphics
        sfml-network
        sfml-system
        pthread
)

enable_testing()
target_compile_options(game_engine PRIVATE)
