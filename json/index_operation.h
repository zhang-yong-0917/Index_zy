//
// Created by zy on 2022/1/22.
//

#ifndef INDEX_ZY_INDEX_OPERATION_H
#define INDEX_ZY_INDEX_OPERATION_H

#include "cJSON.h"

typedef struct TAG{
    char* tag_name;
    char* tag_values;
    struct TAG *next;
};
typedef struct Insert_index{
 char* tbname;
 TAG* tag;
 char* timestamp;
 char* operation;
};


typedef struct Select_index{
    char* tbname;
    TAG* tag;
    char* fields;
    char* timestamp;
    char* operation;
};
//typedef struct Delete_index{
//    char* tbname;
//    TAG* tag;
//    char* timestamp;
//    char* operation;
//};

void insert_json(cJSON *item);
void delete_json(cJSON *item);
void select_json(cJSON *item);
#endif //INDEX_ZY_INDEX_OPERATION_H
