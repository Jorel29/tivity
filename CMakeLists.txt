cmake_minimum_required(VERSION 3.10)

project(Task)

add_executable(TaskTest "./src/unit_test.cpp" "./src/task.h" "./src/task.cpp" "./src/doctest.h")

target_compile_features(TaskTest PUBLIC cxx_std_23)
