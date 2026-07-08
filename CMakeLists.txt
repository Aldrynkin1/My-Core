cmake_minimum_required(VERSION 3.10)
project(My_Core)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}")

add_compile_definitions(
    PROJECT_ROOT_DIR="\\"${CMAKE_SOURCE_DIR}\\""
    CMAKE_CURRENT_SOURCE_DIR="\\"${CMAKE_CURRENT_SOURCE_DIR}\\""
)

include_directories("core/src" "core/include" "core/tests"
                        "core/c_include" "core/c_include/include" "core/c_include/src"
                            "core/create_destroy")

add_library(My_Core STATIC
    main.cpp
    core/src/Timer.cpp
    core/src/FileLogger.cpp
    core/src/Logger.cpp
    core/src/MyException.cpp
    core/c_include/src/allocator.c
    core/src/AI.cpp
    core/src/MultiLayer.cpp
    core/src/ConsoleWriterColors.cpp
    game/src/Monster.cpp
    game/src/Gun.cpp
    game/src/Creature.cpp
    game/src/Human.cpp
)

target_include_directories(My_Core PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/core/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/core/c_include/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/game/include"
)

add_executable(GameApp
    main.cpp
)

target_include_directories(GameApp PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/game/include"
)

target_link_libraries(GameApp PRIVATE My_Core)

add_executable(CoreTests
    core/tests/allocator_test.cpp
    core/tests/MyVector_test.cpp
    core/tests/logger_test.cpp
    core/tests/Timer_test.cpp
    core/tests/Ai_test.cpp
    core/tests/ConsoleColors_test.cpp
)

target_link_libraries(CoreTests PRIVATE My_Core)

add_custom_target(run
    COMMAND $<TARGET_FILE:GameApp>
    WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
    DEPENDS GameApp
    COMMENT "Running the game application..."
)
