# CMakeLists.txt

cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(LeetCodeSolutions)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
SET(CMAKE_BUILD_TYPE "Debug")

# 查找 solutions 目录下的所有 .cpp 文件
file(GLOB_RECURSE solution_files "solutions/*.cpp")


# 遍历每个 .cpp 文件，并创建独立的可执行目标
foreach(solution_file ${solution_files})
    # 获取文件名（不带路径和扩展名），例如 s1, s2
    get_filename_component(solution_name ${solution_file} NAME_WE)

    # 为每个文件添加可执行目标
    add_executable(${solution_name} ${solution_file})
endforeach()