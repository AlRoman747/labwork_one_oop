cmake_minimum_required(VERSION 3.20)

project(Task14 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# ==========================================
# Основной код проекта
# ==========================================

add_library(task14
    src/str_ops.cpp
    src/task_14.cpp
)

target_include_directories(task14
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# ==========================================
# Основная программа
# ==========================================

add_executable(main
    src/main.cpp
)

target_link_libraries(main
    PRIVATE
        task14
)

# ==========================================
# GoogleTest
# ==========================================

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)

# Для Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# ==========================================
# Тесты
# ==========================================

enable_testing()

add_executable(tests
    tests/test_basic_functions.cpp
)

target_link_libraries(tests
    PRIVATE
        task14
        GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(tests)