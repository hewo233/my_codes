#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

#define ElemType int

//节点
typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node, *PNode;

/*
管理结构
本质上更方便于 指来指去
*/
typedef struct List
{
    PNode first;
    PNode last;
    size_t size;//记录有效节点数
}List;

void InitList(List *list);

