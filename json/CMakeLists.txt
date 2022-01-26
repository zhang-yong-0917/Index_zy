AUX_SOURCE_DIRECTORY(. DIR_TEST3_SRCS)
add_executable ( json ${DIR_TEST3_SRCS} test.cpp cJSON.cpp cJSON.h sql_json.cpp sql_json.h  index_operation.cpp index_operation.h)