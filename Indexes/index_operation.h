//
// Created by zy on 2022/1/22.
//

#ifndef INDEX_ZY_INDEX_OPERATION_H
#define INDEX_ZY_INDEX_OPERATION_H

#include <ctime>
#include "sql.h"

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

enum TokenType{
    Asc,
    Desc,
    Max,
    Min,
    SELECT,
    Add ,
    Drop,
    Alter_Add_Column,
    Alter_Drop_Column,
    Database_Name,        //数据库名
    Column_Name,          //列名
    From_TableName,
    Alter_Table,
    LIMIT_Param,
    GROUPBY_Column,
    Select_Column,
    Where_Column,
    DataType,
    FROM,
    WHERE,
    AND,                 //交
    OR,                  //并
    NOT,                 //补
    LIMIT,
    GROUPBY,
    Function,
    Select_ColumnName,
    Alter,
    Create,
    GE,                   //>=
    GT,                   //>
    EQ,                   //==
    LE,                   //<=
    LT,                   //<
    LeftParen,            //(
    RightParen,           //)
    Assignment,           //=
    START,                //*
    COMMA,                //,
    END,                  //;
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
//存红黑树（二级索引）的时间戳集
typedef struct rbtree_result_timestamp{
    char* timestamp;
    struct rbtree_result_timestamp* next;
}Result;

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


//生成过滤的结构体，之后将数据填入，运行刘闯的方法。
typedef struct pri{
    char* res;
    int columNum;
    int aim_values;
    TokenType type;

}PRI;

void create_rbtree_index(tuple_head *pHead);
void create_skip_index(tuple_head* tupleHead);
void delete_index(tuple_head* tupleHead);
void find_rbtree_data(char* swar,sql_operation* sql,tuple_head* tupleHead);
char* find_skip_data(char* database_tablename, char* timestamps, char*  databasename);

#endif //INDEX_ZY_INDEX_OPERATION_H
