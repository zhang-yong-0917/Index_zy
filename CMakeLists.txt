cmake_minimum_required(VERSION 3.19)
project(Index_zy)

set(CMAKE_CXX_STANDARD 14)
#set(SOURCE_FILES  main.cpp)
add_subdirectory(Indexes)
add_subdirectory(json)

aux_source_directory(./Indexes Indexes )
aux_source_directory(./json json )

add_executable(Index_zy IMPORTED  ${Indexes}   ${json})
#target_link_libraries(sql_operation json Indexes)