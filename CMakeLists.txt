cmake_minimum_required(VERSION 3.16)
project(algorithms)

SET(OPTIMIZE                   true)

IF(OPTIMIZE)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
ELSE()
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g")
ENDIF()

INCLUDE(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
SET(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
SET(BIN_NAME "run")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DPROJ_PATH=\"\\\"${PROJECT_SOURCE_DIR}\\\"\"")


INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/examples)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)

FILE(GLOB_RECURSE sourcefiles "examples/*.cpp")

ADD_EXECUTABLE(${BIN_NAME} debug.cpp ${sourcefiles})
TARGET_LINK_LIBRARIES(${BIN_NAME} gtest_main)
ENABLE_TESTING()
INCLUDE(GoogleTest)
gtest_discover_tests(${BIN_NAME})