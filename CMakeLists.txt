cmake_minimum_required(VERSION 3.30)
project(enginey)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(lib/glad EXCLUDE_FROM_ALL)
add_subdirectory(lib/glfw EXCLUDE_FROM_ALL)
add_subdirectory(lib/glm EXCLUDE_FROM_ALL)

include_directories(
        ./lib/stb
)

set(LIBS glad glfw glm m)

add_executable(enginey 
    src/main.cpp
        src/graphics/shader.cpp
        src/graphics/shader.h
        src/graphics/model.cpp
        src/graphics/model.h
        src/graphics/texture.cpp
        src/graphics/texture.h
        src/backend/context.cpp
        src/backend/context.h
        src/backend/camera.cpp
        src/backend/camera.h
        src/math/math.cpp
        src/math/math.h)

target_link_libraries(enginey PUBLIC ${LIBS})

add_custom_command(TARGET enginey POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/res $<TARGET_FILE_DIR:enginey>/res)
