//
// Created by zy on 2022/1/22.
//

#ifndef INDEX_ZY_INDEX_CREATE_H
#define INDEX_ZY_INDEX_CREATE_H

#include <ctime>

//typedef struct Index_Meta{
//    int KeyLength;
//    char* Key;
//};
//typedef struct Index_Entry{
//    char* Maxtime;
//    char* Mintime;
//    int Offset;
//    int Size;
//};
//typedef struct Time_Value{
//    char * timestamps;
//    char*  values;
//    Time_Value* next;
//};
//typedef struct Index_Block{
//    struct Index_Entry* indexEntry;
//    struct Index_Meta* indexMeta;
//};//主要
//typedef struct Data_Block{
//    void* type;//
//    int length;
//    struct Time_Value* timeValue;
//};//主要


 enum DataTypes{
    BYTE=0,
    INT,
    FLOAT,
    DOUBLE,
    DECIMAL,
    VARCHAR,
    TEXT,
    TIME,
    TIMESTAMP=8
};

//======================================

//元组数据
typedef struct tuple{

    char * timestamp;//时间戳
    char * value;//数据的值

    struct tuple * next;
}value_tuple;

typedef struct tuple_column{
    //列名
    char * columnname;
    //数据类型
    enum DataTypes dataTypes;

    //数据
    struct tuple * datalist;

    struct tuple_column * nextcolumn;
};


//元组数据的元数据头节点
typedef struct tuple_head{
    //数据库名
    char * databasename;
    //表名
    char * tablename;

    //属性
    struct tuple_column * fileds;

}head_tuple;
//

typedef struct circularList;

////用于存放数据
//typedef struct circularListNode{
//    //index
//    long index;
//    //数据类型
//    enum DataTypes datatype;
//    //数据
//    value_tuple * values;
//    //偏移量
//    int offsetSize;
//    //下一个数据
//    struct circularListNode* next;
//
//    head_tuple * headdata;
//
////    struct circularList * head;
//
//}CircularNode;



//用于存数据上层信息
typedef struct circularList{
    //数据库名
    char* databaseName;
    //表名
    char* tableName;
    //文件路径
    char* filePath;

    //头节点
//    CircularNode *head;
    time_t earliest_time;

    long int size;  //单位为MB
//
////    long index;
//    CircularNode * next;

    int is_fulied;
}CircularList;

#endif //INDEX_ZY_INDEX_CREATE_H
