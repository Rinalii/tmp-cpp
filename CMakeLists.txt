cmake_minimum_required(VERSION 3.14)
project(cpp_tmp CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- GoogleTest ---
enable_testing()
include(FetchContent)
FetchContent_Declare(googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.14.0)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)

# --- Функция для добавления задачи ---
function(add_task NAME)
    set(DIR  "${CMAKE_SOURCE_DIR}/tasks/${NAME}")
    set(TGT  "${NAME}")
    set(LIB  "${NAME}_lib")

    add_library(${LIB} "${DIR}/src/solution.cpp")
    target_include_directories(${LIB} PUBLIC "${DIR}/include")

    add_executable(${TGT} "${DIR}/src/main.cpp")
    target_link_libraries(${TGT} PRIVATE ${LIB})

    add_executable(${TGT}_tests "${DIR}/tests/test_solution.cpp")
    target_link_libraries(${TGT}_tests PRIVATE ${LIB} GTest::gtest_main)
    gtest_discover_tests(${TGT}_tests)
endfunction()

# --- Регистрируем задачи ---
add_task(task_a_brackets)
