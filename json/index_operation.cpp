////
//// Created by zy on 2022/1/22.
////
//#include "stdio.h"
//#include <cstdlib>
//#include <cstring>
//#include "index_operation.h"
//#include "../Indexes/index_create.h"
//
//void insert_json(cJSON *item);
//void delete_json(cJSON *item);
//void select_json(cJSON *item);
//
//
////static  Index_Block* indexBlock;
////static  Data_Block* dataBlock;
//
////json的strcat，拼接tag;
//char* json_strcat(char* src,int i){
//    char str[1]={(char)i};
//    int len=strlen(src)+ strlen(str);
//    char* a=(char*)malloc(len);
////    a=tag;
////    char tag[len];
////    memset(tag,0,len);
//
//    strcat(a,src);
//    strcat(a,str);
//
////    src=a;
//    return a;
//}
//char* index_strcat(char* src1,char*src2){
//    int src1_len=strlen(src1);
//    int src2_len=strlen(src2);
//    int len=src1_len+src2_len;
//    char* index=(char*) malloc(sizeof(len));
//    strcat(index,src1);
//    strcat(index,src2);
//    return index;
//}
//
//Insert_index*  tag_operation( cJSON *item,Insert_index* insertIndex){
//    TAG* a=(TAG*) malloc(sizeof(TAG));
//    insertIndex->tag->next=a;
//    int i=1;
//
//    char* tag="tag";
//    printf("当前的%s:%s\n",tag,tag);
//    tag=json_strcat(tag,i);//拼接数字和字符串
//
//    char* values="values";
//    printf("当前的%s:%s\n",values,values);
//    values=json_strcat(values,i);//拼接数字和字符串
//    i++;
//
//    if( ((insertIndex->tag->next)->tag_name= cJSON_Print(cJSON_GetObjectItem(item, tag)))!= nullptr){
//        printf("tag1:%s\n",(insertIndex->tag->next)->tag_name);
//        free(tag);//
//
//        insertIndex->tag->tag_values= cJSON_Print(cJSON_GetObjectItem(item, values));
//        printf("values1:%s\n", insertIndex->tag->tag_values);
//        free(values);
//
//        tag_operation(item,insertIndex);
//    }else{
//        free(a);
//    }
//    return insertIndex;
//}
//
//void insert_json(cJSON *item){
//
//    //申请内存
//    Insert_index* insertIndex=(Insert_index*) malloc(sizeof(Insert_index));
//    insertIndex->tag=(TAG*) malloc(sizeof(TAG));
//
//    //获取对应的内容
//    insertIndex->name= cJSON_Print(cJSON_GetObjectItem(item, "name"));
//    printf("name:%s\n",insertIndex->name);
//    //获取对应的内容
//    insertIndex->timestamp= cJSON_Print(cJSON_GetObjectItem(item, "timestamp"));
//    printf("timestamp  :%s\n",insertIndex->timestamp);
//
//    //获取对应的内容
//    (insertIndex->tag)->tag_values= cJSON_Print(cJSON_GetObjectItem(item, "values"));
//    printf("values:%s\n", insertIndex->tag->tag_values);
//
//    //获取对应的内容
//    (insertIndex->tag)->tag_name= cJSON_Print(cJSON_GetObjectItem(item, "tag"));
//    printf("tag:%s\n",insertIndex->tag->tag_name );
//
//                //判断是否有多个tag，有就解析；无，就返回。
//    insertIndex=tag_operation(item,insertIndex);
//    printf("没有\n");
//
//////    strcat(insertIndex->name,(insertIndex->tag)->tag_values);
////
////    indexBlock=(Index_Block*) malloc(sizeof(Index_Block));
////    indexBlock->indexMeta=(Index_Meta*) malloc(sizeof(Index_Block));
////    indexBlock->indexEntry=(Index_Entry*) malloc(sizeof(Index_Entry));
////
////
////    dataBlock=(Data_Block*) malloc(sizeof(Data_Block*));
////    dataBlock->timeValue=(Time_Value*) malloc(sizeof (Time_Value));
////
////    ((indexBlock->indexMeta)->Key)=index_strcat(insertIndex->name,(insertIndex->tag)->tag_name);
////    printf("key:%s\n",(indexBlock->indexMeta)->Key);
////
////
////    (dataBlock->timeValue)->values=(insertIndex->tag)->tag_values;
////    (dataBlock->timeValue)->timestamps=insertIndex->timestamp;
////    printf("时间戳：%s\n",(dataBlock->timeValue)->timestamps);
////    free(username);
//
//    head_tuple *headTuple= (head_tuple*)malloc(sizeof (head_tuple));
//    headTuple->tablename=insertIndex->name;
//    printf("name:%s\n",headTuple->tablename);
//
//}
//
//
//void delete_json(cJSON *item){
//
//}
//
//void select_json(cJSON *item){
//
//}