cmake_minimum_required(VERSION 3.19)
project(Index_zy)

set(CMAKE_CXX_STANDARD 14)
#set(SOURCE_FILES  main.cpp)
add_subdirectory(Indexes)
add_subdirectory(json)
add_subdirectory(sql_operation)

aux_source_directory(./Indexes Indexes )
aux_source_directory(./json json )
aux_source_directory(./sql_operation sql_operation)

add_executable(Index_zy IMPORTED  ${Indexes}  ${sql_operation} ${json})
#target_link_libraries(sql_operation json Indexes)