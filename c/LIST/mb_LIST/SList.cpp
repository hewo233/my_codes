#include"SList.h"

//��ʼ��
void InitList(List *list)
{
    //����ͷ��㣨��ʱͷ���Ҳ��β��㣩
    list->first = list->last = (Node*)malloc(sizeof(Node));
    assert(list->first != NULL);
    //Ϊ�ý�㸳ֵ
    list->first->next = NULL;
    list->size = 0;
}
//β��
void push_back(List *list, ElemType x)
{
    insert(list,end(list),x);    
}

/*
//β��
void push_back(List *list, ElemType x)
{
    //Node *s = _buynode(x);
    //����β����
    Node *s = (Node *)malloc(sizeof(Node));
    assert(s != NULL);
    //Ϊβ���㸳ֵ
    s->data = x;
    s->next = NULL;
    
    //��β�������ӵ�����β��
    list->last->next = s;
    //���Ĺ�������last��ָ��
    list->last = s;
    //������Ч������
    list->size++;
}
*/
//ͷ��
void push_front(List *list, ElemType x)
{
    insert(list,begin(list),x);
}

/*
//ͷ��
void push_front(List *list, ElemType x)
{
    //Node *s = _buynode(x);
    //����ͷ����
    Node *s = (Node *)malloc(sizeof(Node));
    assert(s != NULL);
    s->data = x;
    //��ͷ�������ӵ�������
    s->next = list->first->next;
    list->first->next = s;
    //�������ǲ���ĵ�һ����Ч��㣬��Ҫ����βָ���ָ��
    if(list->size == 0)
    {
        list->last = s;
    }
    //������Ч������
    list->size++;
}
*/

//��ӡ�����е�����
void show_list(List *list)
{
    Node *p = list->first->next;
    while(p != NULL)
    {
        printf("%d-->",p->data);
        p = p->next;
    }
    printf("Nul.\n");
}

//β��ɾ��
void pop_back(List *list)
{
    //�����Ƿ��н�㣿
    if(list->size == 0)
        return;
    //Ѱ�ҵ����ڶ������
    Node *p = list->first;
    while(p->next != list->last)
        p = p->next;
    //ɾ��β���
    free(list->last);
    //����βָ���ָ��
    list->last = p;
    //��������β����ָ����
    list->last->next = NULL;
    //������Ч�����
    list->size--;
}

//ͷ��ɾ��
void pop_front(List *list)
{
    //�������Ƿ���Ԫ�أ�
    if(list->size == 0)
        return;
    //��ʱ����Ҫɾ�����ĵ�ַ
    Node *p = list->first->next;
    //ɾ���ý�������������
    list->first->next = p->next;
    //ɾ�����
    free(p);
    //�������Ƿ�ֻ��һ����Ч���
    if(list->size == 1)
    {
        //����βָ���ָ��
        list->last = list->first;
    }
    //������Ч������
    list->size--;
}

//��ֵ���루ǰ���������ڵ����ݴ�С��������
void insert_val(List *list, ElemType x)
{
    Node *s = _buynode(x);
    /*
    //����Ҫ�����������
    Node *s = (Node *)malloc(sizeof(Node));
    assert(s != NULL);
    s->data = x;
    s->next = NULL;
    */
    //����Ҫ�����λ��
    Node *p = list->first;
    while(p->next!=NULL && p->next->data<x)
        p = p->next;
    
    //���λ���Ƿ�Ϊβ����
    if(p->next == NULL)
    {
        //���Ϊβ���޸�βָ��λ��
        list->last = s;
    }
    //��������
    s->next = p->next;
    p->next = s;
    //������Ч������
    list->size++;
}

//��������
Node* find(List *list, ElemType key)
{
    Node *p = list->first->next;
    while(p!=NULL && p->data!=key) 
        p = p->next;
    return p;
}

//������Ч���ĸ���
int  length(List *list)
{
    return list->size;
}
/*
//����ֵ��ɾ������һ������Ҫɾ�����λ��������ɾ��
void delete_val(List *list, ElemType key)
{
    //�����Ƿ�Ϊ�գ�
    if(list->size==0)
        return;
    //���ҵ�Ҫɾ������λ��
    Node *p = find(list,key);
    //���û���ҵ�
    if(p == NULL)
    {
        printf("Ҫɾ�������ݲ�����.\n");
        return;
    }
    //����ҵ�������������β���
    if(p == list->last)
    {
        //�����������βɾ
        pop_back(list);
    }
    else//ɾ��������������һ��㵽��ǰ��㣬ɾ����һ���
    {
        //������һ���ָ��
        Node *q = p->next;
        //������һ���
        p->data = q->data;
        p->next = q->next;
        //ɾ����һ���
        free(q);
        //������Ч�����
        list->size--;
    }    
}
*/


//����ֵ��ɾ��������������Ҫɾ������ǰ�����λ��������ɾ��
void delete_val(List *list, ElemType key)
{
    //�����Ƿ�Ϊ�գ�
    if(list->size==0)
        return;
    //���ҵ�Ҫɾ������ǰ��λ��
    Node *p = list->first;
    while(p->next!=NULL && p->next->data!=key)
        p=p->next;
    //���û���ҵ�
    if(p->next== NULL)
    {
        printf("Ҫɾ�������ݲ�����.\n");
        return;
    }
    //����ҵ�������������β���
    if(p->next == list->last)
    {
        //�����������βɾ
        pop_back(list);
    }
    else
    {
        //����Ҫɾ������ָ��
        Node *q = p->next;
        //ɾ����������������
        p->next = q->next;
        //ɾ�����
        free(q);
        //������Ч�����
        list->size--;
    }    
}


//����(��С��������)
void sort(List *list)
{
    //��Ч���������<=1��
    if(list->size==0 || list->size==1)
        return;

    /*  ������ֳ���������s��q  */    
    Node *s = list->first->next; //�����һ�������ָ��    
    Node *q = s->next;  //����ڶ��������ָ��

    /*�Ͽ��������������*/
    list->last = s;  
    list->last->next = NULL;

    //�ڶ��������Ƿ��н�㣿
    while(q != NULL) 
    {
        /*�ӵڶ��������в���ȡ����㣬�����һ������*/
        s = q; //�ӵڶ���������ȡ��һ�����
        q = q->next;//ȡ��һ������q����һλ

        //�ڵ�һ�������в���Ҫ�������ǰ�����
        Node *p = list->first;
        while(p->next!=NULL && p->next->data<s->data)
            p = p->next;
        
        //���Ҫ�������λ���ڵ�һ������β��
        if(p->next == NULL)
        {
            //�޸�βָ��
            list->last = s;
        }
        //����
        s->next = p->next;
        p->next = s;
    }
}

//����
void resver(List *list)
{
    if(list->size==0 || list->size==1)
        return;
    /*  ������ֳ���������s��q  */
    Node *p = list->first->next;
    Node *q = p->next;
    /*�Ͽ��������������*/
    list->last = p;
    list->last->next = NULL;

    /*�ӵڶ��������в���ȡ����㣬ͷ�嵽��һ������*/
    while(q != NULL)
    {    
        //�ӵڶ���������ȡ�����
        p = q;
        q = p->next;
        //ͷ�嵽��һ������
        p->next =list->first->next;
        list->first->next = p;
    }
}

//���������(�ͷ����е���Ч���)
void clear(List *list)
{
    //�Ƿ�����Ч���?
    if(list->size == 0)
        return;

    Node *p = list->first->next;
    //����Ч���ȫ���ͷ�
    while(p != NULL)
    {
        list->first->next = p->next;
        free(p);
        p = list->first->next;
    }
    //��Ч���ɾ�����֮�󣬸���βָ�����Ч������
    list->last = list->first;
    list->size = 0;
}
//����(�ͷ����н�㼴����ͷ������Ч���)
void destroy(List *list)
{
    //�ͷ���Ч���
    clear(list);
    //�ͷ�ͷ���
    free(list->first);
    //��ͷ����β����ÿ�
    list->first = list->last = NULL;
}

//�����Ż�
//���ɽ��
Node* _buynode(ElemType x)
{
    //Ϊ������ռ�
    Node *s = (Node *)malloc(sizeof(Node));
    assert(s != NULL);
    //Ϊ�ý���������ֵ
    s->data = x;
    //��Ӧָ���򣬵�����������ʱ�ٶ�����и�ֵ��Ŀǰ���ÿ�
    s->next = NULL;
    return s;
}
//���ص�һ����Ч���
It begin(List *list)
{
    return list->first->next;
}
//����β������һ���(�ս��)
It end(List *list)
{
    return list->last->next;
}
//�������ĳ�����ǰ�������
void insert(List *list, It pos, ElemType x)
{
    //�ҵ����Ҫ�����λ��
    Node *p = list->first;
    while(p->next != pos)
    {
        p = p->next;
    }
    //��ȡһ�����
    Node *s = _buynode(x);
    //���ý���������
    s->next = p->next;
    p->next = s;
    //����������λ����β������Ҫ����βָ���ֵ
    if(pos == NULL)
        list->last = s;
    //������Ч������
    list->size++;
}
