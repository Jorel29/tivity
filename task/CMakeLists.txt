cmake_minimum_required(VERSION 3.10)

project(Task)

add_executable(TaskManager "task_manager.cpp" "task.h" "task.cpp")

target_compile_features(TaskManager PUBLIC cxx_std_23)
