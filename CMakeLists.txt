cmake_minimum_required(VERSION 3.16)

# 项目名称
project(my_test_cJSON)

# 设置 C++ 标准
set(CMAKE_C_STANDARD 11)
# set(CMAKE_CXX_STANDARD 11)
# add_compile_options(-std=c++17)

# 包含的头文件目录
# include_directories(./include)
# include_directories(${PROJECT_SOURCE_DIR}/src)
# set(SRC_DIR ./src)

# 指定生产链接库
add_library(cJSON cJSON.c)
add_library(main main.c)

# 设置变量
set(LIBRARIES cJSON main)
set(OBJECT my_test_cJSON)

# 生成可执行文件
# add_executable(main test7.main.cpp)
add_executable(${OBJECT} main.c)

# 为可执行文件链接目标库
target_link_libraries(${OBJECT} ${LIBRARIES} m)