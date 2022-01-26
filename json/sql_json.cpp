//
// Created by zy on 2022/1/17.
//

#include <stdio.h>
#include <cstdlib>
#include "sql_json.h"
#include "cJSON.h"
#include "index_operation.h"

void sql_json(char const  *str) {

    cJSON * sql_root_json=cJSON_Parse(str);//将字符串解析成json结构体

    if (sql_root_json == NULL  )
    {
        printf("error:%s\n", cJSON_GetErrorPtr());
        cJSON_Delete(sql_root_json);
        return;
    }

    //插入操作
    cJSON *sql_insert_json = cJSON_GetObjectItem(sql_root_json, "insert");
    if (sql_insert_json != NULL)
    {
        insert_json(sql_insert_json);
//        char *name = cJSON_Print(sql_insert_json);    //将JSON结构体打印到字符串中 需要自己释放
//        printf("name:%s\n", name);
//        free(name);
        return;
    }

    //查找操作
    cJSON *sql_select_json = cJSON_GetObjectItem(sql_root_json, "select");
    if (sql_select_json != NULL)
    {
        char *name = cJSON_Print(sql_select_json);    //将JSON结构体打印到字符串中 需要自己释放
        printf("name:%s\n", name);
        free(name);
    }

    //删除insert操作
    cJSON *sql_delete_json = cJSON_GetObjectItem(sql_root_json, "delete");
    if (sql_delete_json != NULL)
    {
        char *name = cJSON_Print(sql_delete_json);    //将JSON结构体打印到字符串中 需要自己释放
        printf("name:%s\n", name);
        free(name);
    }


    return;
}
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