//
// Created by zy on 2022/1/17.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include "sql_json.h"
#include "cJSON.h"
#include "index_operation.h"
#include "../Indexes/index_operation.h"




void use_database(char* databasename){

    head_tuple * headTuple=(head_tuple*) malloc(sizeof(head_tuple));
    headTuple->databasename=databasename;
    printf("use_database: %s\n",headTuple->databasename);
}
 char * check_sql(  char* str ){

//    char* databasename= nullptr;
    int len = strlen(str);
     char* swap=(char*) malloc(sizeof (char*));

    for (int i = 0; i < len; ++i) {
        if ((*str=='u'||*str=='U') &&(*(str+1)=='s'||*(str+1)=='S')&&(*(str+2)=='e'||*(str+2)=='E')) {
            str=str+3;
            int swap_len=strlen(str);
            for (int j = 0; j <swap_len; ++j) {
                if (*str==' ') str=str+1;
                if (*str=='\;') break;
                swap[j]=*str;
                str=str+1;
            }
//            strcat(databasename,str);
            printf("check_sql: %s\n",swap);
            use_database(swap);
        }else str=str+1;
    }
//     printf("use databasename语法错误\n");
}

//
//void sql_json(char const  *str) {
//
//    cJSON * sql_root_json=cJSON_Parse(str);//将字符串解析成json结构体
//
//    if (sql_root_json == NULL  )
//    {
//        printf("error:%s\n", cJSON_GetErrorPtr());
//        cJSON_Delete(sql_root_json);
//        return;
//    }
//
//
//    //插入操作
//    cJSON *sql_insert_json = cJSON_GetObjectItem(sql_root_json, "insert");
//    if (sql_insert_json != NULL)
//    {
//        insert_json(sql_insert_json);
////        char *name = cJSON_Print(sql_insert_json);    //将JSON结构体打印到字符串中 需要自己释放
////        printf("name:%s\n", name);
////        free(name);
//        return;
//    }
//
//    //查找操作
//    cJSON *sql_select_json = cJSON_GetObjectItem(sql_root_json, "select");
//    if (sql_select_json != NULL)
//    {
//        char *name = cJSON_Print(sql_select_json);    //将JSON结构体打印到字符串中 需要自己释放
//        printf("name:%s\n", name);
//        free(name);
//    }
//
//    //删除insert操作
//    cJSON *sql_delete_json = cJSON_GetObjectItem(sql_root_json, "delete");
//    if (sql_delete_json != NULL)
//    {
//        char *name = cJSON_Print(sql_delete_json);    //将JSON结构体打印到字符串中 需要自己释放
//        printf("name:%s\n", name);
//        free(name);
//    }
//
//    return;
//}


int main(){
    char  *a="{   \"insert\":{\n"
                  "        \"name\":[\n"
                  "                    {\n"
                  "                     \"name\":\"student\",\n"
                  "                     \"tag\":\"score\",\n"
                  "                     \"values\":80,\n"
                  "                     \"timestamp\":1488821368327436809\n"
                  "                     }\n"
                  "        ]\n"
                  "    }\n"
                  "}";
    char *b="use student;";
//    sql_analysis(b);
  b= check_sql(b);
//    sql_json(a);

}