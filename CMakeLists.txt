cmake_minimum_required(VERSION 3.7)

project(example-project)

list(APPEND CMAKE_PREFIX_PATH "$ENV{userprofile}/.cpppm/install")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_PREFIX_PATH}/cmake)

find_package(SDL2 REQUIRED)
find_package(BULLET REQUIRED)
find_package(OPENGL REQUIRED)

add_executable(example-exe
    src/program.cpp
    src/glad.c
    )

target_include_directories(example-exe
    PRIVATE ${BULLET_INCLUDE_DIR}
    PRIVATE include
    )

target_link_libraries(example-exe
    SDL2::SDL2-static
    ${OPENGL_LIBRARIES}
    ${BULLET_LIBRARIES}
    )
