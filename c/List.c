#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

#define ElemType int

//�ڵ�
typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node, *PNode;

/*
����ṹ
�����ϸ������� ָ��ָȥ
*/
typedef struct List
{
    PNode first;
    PNode last;
    size_t size;//��¼��Ч�ڵ���
}List;

void InitList(List *list);

