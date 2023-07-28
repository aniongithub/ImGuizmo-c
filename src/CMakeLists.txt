cmake_minimum_required(VERSION 3.13)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "*.cpp" "*.h")
target_sources(${PROJECT_NAME}
    PRIVATE
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include> 
        ${SOURCES})