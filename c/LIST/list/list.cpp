#include "list.h"

//初始化
void InitList(tList *list)
{
    list->first = list->last = (tNode*)malloc(sizeof(tNode));
    assert(list->first != nullptr);//这个大概是为了防炸？
    list->first->next = nullptr;
    list->size = 0;
}

/*

//尾插操作
void push_back(tList *list ,ElemType x)
{
    tNode *s = (tNode *)malloc(sizeof(tNode));//有意思的开地址方式
    assert(s != nullptr);
    s->data = x;
    s->next = nullptr;
    list->last->next = s;//让 last 指向 s
    list->last = s;
    list->size++;
}

void push_front(tList *list,ElemType x)
{
    tNode *s = (tNode *)malloc(sizeof(tNode));
    assert(s != nullptr);
    s->data = x;
    s->next = list->first->next;
    list->first->next = s;
    if(list->size == 0)
    {
        list->last = s;//如果是第一个的话，尾指针也要改
    }
    list->size++;
}

*/

//上面是一种老实的实现方法，但是我们也可以有优化

//首先整合代码

//用来生成一个 tNode 类型的 s, 并且返回 s
tNode* _getNode(ElemType x)
{
    auto *s = (tNode *)malloc(sizeof(tNode));
    assert(s != nullptr);
    s->data = x;
    s->next = nullptr;
    return s;
}


//无需多盐
tNode* begin(tList *list)
{
    return list->first->next;
}

tNode* end(tList *list)
{
    return list->last->next;
}

void insert(tList *list,tNode* position,ElemType x)
{
    tNode *p = list->first;
    while(p->next != position)//巧妙的二合一
    {
        p = p->next;
    }
    tNode *s = _getNode(x);
    s->next = p -> next;
    p->next = s;
    if(position == nullptr) list->last = s;
    list->size++;
}

void push_back(tList *list,ElemType x)
{
    insert(list,end(list),x);
}

void push_front(tList *list,ElemType x)
{
    insert(list,end(list),x);
}

//打印
void print_list(tList *list)
{
    tNode *p = list->first->next;//有 first 就是方便
    while (p != nullptr)
    {
        printf("%d ---> ", p->data);
        p = p->next;
    }
    printf("OVER!\n");
}

//头部删除
void del_front(tList *list)
{
    if(list->size == 0) return ;
    tNode *p = list->first->next;
    list->first->next = p->next;
    free(p);
    if(list->size == 1)//最后一个删头就是删尾
    {
        list->last = list ->first;
    }
    list->size--;
}

void del_back(tList *list)
{
    if(list->size == 0) return ;
    tNode *p = list->first;
    while(p->next != list->last)
    {
        p = p->next;//找到倒数第二个
    }
    free(list->last);
    list->last = p;
    list->last->next = nullptr;
    list->size--;
}

//单调递增时按值插入
void insert_val(tList *list, ElemType x)
{
    tNode *p = list->first;
    while(p->next->data < x && p->next != nullptr)
    {
        p = p->next;
    }
    insert(list,p,x);
}

//找到该值对应的地址
tNode* find(tList *list,ElemType key)
{
    tNode *p = list->first->next;
    while(p->data != key && p != nullptr)
    {
        p = p->next;
    }
    return p;
}

//返回长度
int length(tList *list)
{
    return list->size;
}

//按值删除
void del_val(tList *list ,ElemType key)
{
    if(list->size == 0) return ;//你删牛魔
    tNode *p = list->first;
    while(p->next->data != key && p->next !=nullptr)
    {
        p = p->next;
    }
    if(p->next == nullptr)
    {
        printf("你删了个牛魔\n");
        return;
    }
    if(p->next == list->last)
    {
        del_back(list);
    }
    else
    {
        tNode *q = p->next;
        p -> next =q -> next;
        free(q);
        list->size--;
    }
}

//递增排序
void sort(tList *list)
{
    if(list->size <= 1) return ;//你排牛魔
    tList* sort_list;
    InitList(sort_list);
    tNode *s = list->first->next;
    push_front(sort_list,s->data);
    while(s->next != nullptr)
    {
        s = s->next;
        insert_val(sort_list,s->data);
    }
    *list = *sort_list;
    free(sort_list);
}











