# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
project (db_conn)

aux_source_directory(. DIR_SRCS)

# 指定生成目标
add_executable(c_mysql_conn c_mysql_conn.cpp)
target_link_libraries (c_mysql_conn  mysqlclient)

add_executable(cpp_mysql_conn cpp_mysql_conn.cpp)
target_link_libraries (cpp_mysql_conn  mysqlcppconn)
