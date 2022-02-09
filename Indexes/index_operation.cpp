//
// Created by zy on 2022/1/22.
//

#include <malloc.h>
#include <cstring>
#include "index_operation.h"
#include "skip_list.h"
#include "rb_tree.h"
#include "../G++Test/database_engine.h"

static skip_list* skipList;
static RBRoot * rbRoot;


void* Pri_fifltra(PRI*　pri, Link_Node * head){

//Link_Node *head = new(Link_Node);



//switch (pri->type) {
//    case Assignment: {//=
//
//    duty_node *srceen_datas = new(class duty_node);
//    srceen_datas->init_node(SrceenDatas,pri->res,pri->columNum,pri->aim_values,pri->type);
//    duty_register(head,srceen_datas);
//    break;
//}
//
//    case GT:{//>
//
//    duty_node *srceen_datas = new(class duty_node);
//    srceen_datas->init_node(SrceenDatas,pri->res,pri->columNum,pri->aim_values,pri->type);
//    duty_register(head,srceen_datas);
//    break;
//}
//    case LT:{//<
//    duty_node *srceen_datas = new(class duty_node);
//    srceen_datas->init_node(SrceenDatas,pri->res,pri->columNum,pri->aim_values,pri->type);
//    duty_register(head,srceen_datas);
//    break;
//}
//    case GE:{//>=
//        duty_node *srceen_datas = new(class duty_node);
//        srceen_datas->init_node(SrceenDatas,pri->res,pri->columNum,pri->aim_values,pri->type);
//        duty_register(head,srceen_datas);
//        break;
//}
//    case LE:{//<=
//    duty_node *srceen_datas = new(class duty_node);
//    srceen_datas->init_node(SrceenDatas,pri->res,pri->columNum,pri->aim_values,pri->type);
//    duty_register(head,srceen_datas);
//    break;
//
//}
//    case AND:{
//    duty_node *set_c = new(class duty_node);
//    set_c->init_node(Set_operation,pri->res,pri->columNum,pri->aim_values,pri->type);
//    duty_register(head,set_c);
//    break;
//}
//    case OR:{
//    duty_node *set_c = new(class duty_node);
//    set_c->init_node(Set_operation,pri->res,pri->columNum,pri->aim_values,pri->type);
//    duty_register(head,set_c);
//    break;
//}
//    case LIMIT:{
//    duty_node *limit = new (class duty_node);
//    limit->init_node(limit_data,pri->res,pri->columNum,pri->aim_values,pri->type);
//    duty_register(head,limit);
//    break;
//}
//    case Asc:{
//    duty_node *sort_data = new (class duty_node);
//    sort_data->init_node(SortOrChange,pri->res,pri->columNum,pri->aim_values,pri->type);
//    duty_register(head,sort_data);
//    break;
//}
//    case Desc:{
//    duty_node *sort_data = new (class duty_node);
//    sort_data->init_node(SortOrChange,pri->res,pri->columNum,pri->aim_values,pri->type);
//    duty_register(head,sort_data);
//    break;
//}
//    default:{
////                //????????
////                pri->aim_values=0;
////                pri->columNum=0;
////                pri->type=Assignment;
////
//        break;
//}
//
//}

return *head;
}

void Pri_end(Link_Node ** head){
//    Log_info(run_task(*head));
}
void create_skip_index(tuple_head* tupleHead){
    int len= strlen(tupleHead->databasename)+ strlen(tupleHead->tablename);
    char swar[len+1];
    memset(swar,0,len+1);//初始化
    strcat(swar,tupleHead->databasename);
    strcat(swar,"_");
    strcat(swar,tupleHead->tablename);
    skipList= find_skiptable(swar);//查找跳表
    printf("swar:%s\n",swar);
    if(skipList==NULL) printf("该跳表不存在");

    int timestamp= atoi(tupleHead->fileds->datalist->timestamp);//字符串转int
    if(skipList!=NULL){

        insert_x_into_skip_list(skipList, timestamp,tupleHead->fileds);
    }
    else{
        perror("跳表未创建\n");
    }

}
char*  pick_sql(tuple_column* tupleColumn){
//弄成刘创的字符串
    char* a=(char*) malloc(sizeof(char));
    memset(a,0, strlen(a));
    char* time=tupleColumn->datalist->timestamp;
    strcat(a,time);

    while(tupleColumn!=NULL){
        //判断是否属于同一时间下
            if (time!=tupleColumn->datalist->timestamp) perror("时间不一致");
                time=tupleColumn->datalist->timestamp;

            strcat(a,",");
            strcat(a,tupleColumn->datalist->value);;

            //时间窗口，多条数据；
//            if (tupleColumn->datalist->next!=NULL) ;

            tupleColumn=tupleColumn->nextcolumn;

        }

    strcat(a,";");

    return a;
}
//一级索引查找
char* find_skip_data(char* database_tablename, char* timestamps, char*  databasename){

    skipList= find_skiptable(database_tablename);//查找跳表
    printf("databaseTablename:%s\n", database_tablename);
    if(skipList==NULL) printf("该跳表不存在");
    int timestamp= atoi(timestamps);//字符串转int


    data_node * dataNode= (data_node*)malloc(sizeof(data_node));//记得free
    if (timestamp!=NULL){//判断是否有主健

        dataNode=find_x_from_skip_list(skipList, timestamp);//查找一级索引

        if (dataNode->indexEntry->Offset==NULL){
                                                            //时间窗口，多条数据；
            tuple_column *b= time_window(databasename,(char*)dataNode->key,(char*)dataNode->key);  //去环形列表查询
            return  pick_sql(b);//生成刘创的结构
        }
        VfsNode* tablePath= findDataBaseByName(databasename);
        char *path=tablePath->filepath;

        tuple_column *a= search_disk(databasename,path,dataNode->indexEntry->Offset,dataNode->indexEntry->Size); //去落盘查询
       return pick_sql(a);
    }

}
//二级索引查找
void find_rbtree_data(char* database_tablename,sql_operation* sql,tuple_head* tupleHead){
    rbRoot= find_rbTree(database_tablename);
    sql_operation* swap=sql;
    rbtree_result_timestamp*  result;

    Link_Node *head = new(Link_Node);
    //查找根据客户要查找数据，进行查找并且将结果集返回到resultt
    while(swap->data_list!=NULL){
        rbtree_result_timestamp*  a;
//        =(rbtree_result_timestamp*) malloc(sizeof(rbtree_result_timestamp));
       a= rbtree_search(rbRoot,swap->data_list->c_name,swap->data_list->c_value,swap->data_list->c_symbol);
       result->next=a;


    //根据客户需求生成对应的 struct条件过滤：刘创那部分，形成结构体。
        PRI * pri=(PRI*) malloc(sizeof(PRI));
        sql_operation * sql=(sql_operation*) malloc(sizeof(sql_operation));
        sql= get_map_node(database_tablename);

        switch (swap->data_list->c_symbol) {

            case Assignment: {//=
                int columNum=0;
                //根据表结构（sql）判断查询的列，是在第几个位置
                while (swap->data_list->c_name!=sql->data_list->c_name && sql->data_list->c_name !=NULL){
                    ++columNum;
                    sql->data_list=sql->data_list->next;
                }
                if (sql->data_list->c_name==NULL) { perror("[error] 插入的数据，表中没有"); break; }
                else {
                    pri->columNum=columNum;

                    pri->type=Assignment;

                    int aim= atoi(swap->data_list->c_value);
                    pri->aim_values=aim;
                }


                while(result->timestamp!=NULL){
                    char *str;
                    //进行结果拼接
                   str= find_skip_data(database_tablename,result->next->timestamp,tupleHead->databasename);
                    strcat(pri->res,str);
                }
                Pri_fifltra(pri,head);//创建Pri

                break;
            }

            case GT:{//>

                int columNum=0;
                //根据表结构（sql）判断查询的列，是在第几个位置
                while (swap->data_list->c_name!=sql->data_list->c_name && sql->data_list->c_name !=NULL){
                    ++columNum;
                    sql->data_list=sql->data_list->next;
                }
                if (sql->data_list->c_name==NULL) { perror("[error] 插入的数据，表中没有"); break; }
                else {
                    pri->columNum=columNum;

                    pri->type=GT;

                    int aim= atoi(swap->data_list->c_value);
                    pri->aim_values=aim;
                }

                while(result->timestamp!=NULL){

                    char *str;
                    //进行结果拼接
                    str= find_skip_data(database_tablename,result->next->timestamp,tupleHead->databasename);
                    strcat(pri->res,str);
                }
                Pri_fifltra(pri,head);//创建Pri
                break;
            }
            case LT:{//<

                int columNum=0;
                //根据表结构（sql）判断查询的列，是在第几个位置
                while (swap->data_list->c_name!=sql->data_list->c_name && sql->data_list->c_name !=NULL){
                    ++columNum;
                    sql->data_list=sql->data_list->next;
                }
                if (sql->data_list->c_name==NULL) { perror("[error] 插入的数据，表中没有"); break; }
                else {
                    pri->columNum=columNum;

                    pri->type=LT;

                    int aim= atoi(swap->data_list->c_value);
                    pri->aim_values=aim;
                }

                while(result->timestamp!=NULL){
                    char *str;
                    //进行结果拼接
                    str= find_skip_data(database_tablename,result->next->timestamp,tupleHead->databasename);
                    strcat(pri->res,str);
                }
                Pri_fifltra(pri,head);//创建Pri


                break;
            }
            case GE:{//>=
                int columNum=0;
                //根据表结构（sql）判断查询的列，是在第几个位置
                while (swap->data_list->c_name!=sql->data_list->c_name && sql->data_list->c_name !=NULL){
                    ++columNum;
                    sql->data_list=sql->data_list->next;
                }
                if (sql->data_list->c_name==NULL) { perror("[error] 插入的数据，表中没有"); break; }
                else {
                    pri->columNum=columNum;

                    pri->type=GE;

                    int aim= atoi(swap->data_list->c_value);
                    pri->aim_values=aim;
                }

                while(result->timestamp!=NULL){
                    char *str;
                    //进行结果拼接
                    str= find_skip_data(database_tablename,result->next->timestamp,tupleHead->databasename);
                    strcat(pri->res,str);
                }
                Pri_fifltra(pri,head);//创建Pri
                break;
            }
            case LE:{//<=

                int columNum=0;
                //根据表结构（sql）判断查询的列，是在第几个位置
                while (swap->data_list->c_name!=sql->data_list->c_name && sql->data_list->c_name !=NULL){
                    ++columNum;
                    sql->data_list=sql->data_list->next;
                }
                if (sql->data_list->c_name==NULL) { perror("[error] 插入的数据，表中没有"); break; }
                else {
                    pri->columNum=columNum;

                    pri->type=LE;

                    int aim= atoi(swap->data_list->c_value);
                    pri->aim_values=aim;
                }
                while(result->timestamp!=NULL){
                    char *str;
                    //进行结果拼接
                    str= find_skip_data(database_tablename,result->next->timestamp,tupleHead->databasename);
                    strcat(pri->res,str);
                }
                Pri_fifltra(pri,head);//创建Pri

                break;

            }

            default:
            {
                //????????
                //还有多余的

                break;
            }
        }


        switch(swap->data_list->cTypes){

            case AND:
            {

                pri->aim_values=0;
                pri->columNum=0;
                pri->type=AND;

                Pri_fifltra(pri,head);//创建Pri

                break;
            }
            case OR:
            {
                pri->aim_values=0;
                pri->columNum=0;
                pri->type=OR;

                Pri_fifltra(pri,head);//创建Pri
                break;
            }
            case LIMIT:
            {
                pri->aim_values=0;

                int a= atoi(swap->data_list->c_value);
                pri->columNum=a;

                pri->type=LIMIT;
                Pri_fifltra(pri,head);//创建Pri
                break;
            }
            case Asc:
            {
                pri->aim_values=0;
                pri->columNum=3;
                pri->type=Asc;
                Pri_fifltra(pri,head);//创建Pri
                break;
            }
            case Desc:
            {
                pri->aim_values=0;


                pri->columNum=3;

                pri->type=Desc;
                Pri_fifltra(pri,head);//创建Pri
                break;
            }
            default: {

                break;
            }
        }


        swap->data_list=swap->data_list->next;

    }

    Pri_end(*head)；//执行过滤
}



void delete_index(tuple_head* tupleHead){

}
void delete_skip_index(tuple_head* tupleHead){
    int len= strlen(tupleHead->databasename)+ strlen(tupleHead->tablename);
    char swar[len+1];
    strcat(swar,tupleHead->databasename);
    strcat(swar,"_");
    strcat(swar,tupleHead->tablename);
    skipList= find_skiptable(swar);//查找跳表


}
void create_rbtree_index(tuple_head *tupleHead) {
    int len= strlen(tupleHead->databasename)+ strlen(tupleHead->tablename);
    char swar[len+1];
    memset(swar,0,len+1);//初始化
    strcat(swar,tupleHead->databasename);
    strcat(swar,"_");
    strcat(swar,tupleHead->tablename);

    rbRoot= find_rbTree(swar);//查找红黑树
    printf("swar:%s\n",swar);
    if(rbRoot==NULL) printf("该红黑树不存在");

    Node * node=(Node*) malloc(sizeof(Node));
    sql_operation * sql=(sql_operation*) malloc(sizeof(sql_operation));
   sql= get_map_node(swar);
   //根据sql构建Node结构
   while(sql->data_list!=NULL){
       if (sql->data_list->c_name!="timestamp"){
           node->tag_values->columnname=sql->data_list->c_name;
           node->tag_values->datalist->timestamp=NULL;
           node->tag_values->datalist->value=NULL;

           node->tag_values=node->tag_values->nextcolumn;
           sql->data_list=sql->data_list->next;
       }else{
           node->tag_values=node->tag_values->nextcolumn;
           sql->data_list=sql->data_list->next;
       }
   }
   //根据tupleHead传入参数到Node里面
   while(tupleHead->fileds!=NULL){
       while(node->tag_values!=NULL){
           if (tupleHead->fileds->columnname==node->tag_values->columnname){
               node->tag_values->datalist->timestamp=tupleHead->fileds->datalist->timestamp;
               node->tag_values->datalist->value=tupleHead->fileds->datalist->value;
           }else{
               node->tag_values=node->tag_values->nextcolumn;
           }
       }
       tupleHead->fileds=tupleHead->fileds->nextcolumn;
}
   //插入数据
    insert_rbtree(rbRoot, node);
//    tupleHead->fileds->datalist.
}


//void create_datablock(Data_Block* dataBlock){
//
//}
