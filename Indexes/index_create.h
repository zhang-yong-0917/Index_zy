//
// Created by zy on 2022/1/22.
//

#ifndef INDEX_ZY_INDEX_CREATE_H
#define INDEX_ZY_INDEX_CREATE_H

typedef struct Index_Meta{
    int KeyLength;
    char* Key;
};
typedef struct Index_Entry{
    char* Maxtime;
    char* Mintime;
    int Offset;
    int Size;
};
typedef struct Time_Value{
    char * timestamps;
    char*  values;
    Time_Value* next;
};
typedef struct Index_Block{
    struct Index_Entry* indexEntry;
    struct Index_Meta* indexMeta;
};//主要
typedef struct Data_Block{
    void* type;//
    int length;
    struct Time_Value* timeValue;
};//主要


#endif //INDEX_ZY_INDEX_CREATE_H
