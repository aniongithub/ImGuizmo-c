cmake_minimum_required(VERSION 3.13)

project(sequencer_sdl2_opengl3)

set(OpenGL_GL_PREFERENCE "GLVND")
find_package(OpenGL REQUIRED)

find_package(SDL2 REQUIRED CONFIG)
find_package(imgui REQUIRED COMPONENTS imgui-core imgui-sdl imgui-opengl3)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${OPENGL_INCLUDE_DIR}
    ${SDL2_INCLUDE_DIRS}
    imgui
    imguizmo)

target_link_libraries(${PROJECT_NAME}
        ${CMAKE_DL_LIBS}
        ${SDL2_LIBRARIES}
        imgui-core
        imgui-sdl
        imgui-opengl3
        OpenGL::GL
        OpenGL::GLX
        ImGuizmoC)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)