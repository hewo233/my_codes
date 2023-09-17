#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#define ElemType int

//单链表的节点
typedef struct tNode
{
    ElemType data;
    struct tNode *next;
}tNode, *pNode;//PNode 是一个类型别名，相当于可以用来定义别人作为一个关于 Node 的指针

typedef struct tList
{
    pNode first;
    pNode last;
    size_t size;//记录有效节点数
}tList;

__attribute__((unused)) void Initlist(tList *list);
tNode* _getNode(ElemType x);