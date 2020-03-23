cmake_minimum_required(VERSION 3.0.0)
project(stepCountingAlgoTest LANGUAGES C VERSION 0.1.0)

include(CTest)
enable_testing()

#Debug flags (sanitizers) for clang
set (CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address -fsanitize=undefined") #-fsanitize=memory 
set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address -fsanitize=undefined")

#Debug flags for gcc
#set (CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall -pg")
#set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -Wall -pg")

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/Step-counting-algo/include)
set(SOURCES, "src/main.c")
file(GLOB SOURCES "src/*.c")
file(GLOB ALGO "Step-counting-algo/src/*.c")

add_executable(stepCountingAlgoTest ${SOURCES} ${ALGO})

target_link_libraries(stepCountingAlgoTest m)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
