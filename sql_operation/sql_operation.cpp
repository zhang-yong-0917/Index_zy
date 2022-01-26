//
// Created by zy on 2022/1/14.
//

#include "sql_operation.h"
#include "../json/sql_json.h"


/**
 * @sql sql解析器传过来json格式的sql语句
 *
 *
 * */
// void sql_json(const char *string);
//void  sql_analysis(char const* sql){
//
//    sql_json(sql);
//}
int main(){
    char const *a="{   \"insert\":{\n"
                  "        \"tbname\":[\n"
                  "                    {\n"
                  "                     \"name\":\"student\",\n"
                  "                     \"tag\":\"score\",\n"
                  "                     \"values\":80,\n"
                  "                     \"timestamp\":1488821368327436809\n"
                  "                     }\n"
                  "        ]\n"
                  "    }\n"
                  "}";
    char *b="xxxx";
//    sql_analysis(b);
    sql_json(a);
}
