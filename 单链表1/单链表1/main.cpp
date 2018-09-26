//
//  单链表.c
//
//
//  Created by Mac on 2018/9/18.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct Linklist  //链表结构体
{
    int data;
    struct Linklist *next;
}Linklist,*link;

void InitList(link &L)   //创建单链表
{
    
    L=(link)malloc(sizeof(Linklist));   //分配内存空间
    L->next=NULL;  //分配链表头
    printf("成功！\n");
}
void Creatlist_L(link &L)  //给单链表插入10个元素
{
    int i;
    link temp=L;     //链表头
    for (i=0;i<=10;i++) //循环10次给单链表赋值
    {
        link a=(link)malloc(sizeof(Linklist));  //每次循环分配一个a的地址空间
        a->data=i;   //给a的data赋值
        a->next=NULL;   //a作为最后一个节点指针为NULL
        temp->next=a;   //使用一个临时指针，这个临时指针指向a
        temp=temp->next;  //每次循环
        printf("成功1！\n");
    }
}
void Linkinsert(link &L,int i,int e)  //在单链表中第i个位置之前插入一个e
{
    link temp=L;
    link s;
    int j=0;
    while (temp&&j<i-1)   //遍历链表寻找第i-1个节点
    {
        temp=temp->next;++j;
    }
    if(!temp||j>i-1)
        printf("错误");  //
        s=(link)malloc(sizeof(Linklist));   //生成新节点
    s->data=e;s->next=temp->next;temp->next=s;//往L中插入e
    printf("成功2！\n");
}
void Listdelete(link &L,int i,int &e) //删除第i个节点上的元素，并返回e的值
{
    link p,temp;
    p=L;
    int j=0;
    while (p->next&&j<i-1)  //寻找节点
    {
        p=p->next;++j;
    }
    if (!p->next||j>i-1)
    {
        printf("删除位置不合理"); //删除位置不合理
        temp=p->next;  //删除这个节点
        p->next=temp->next;
        e=temp->data;
        free(temp);  //释放这个节点
        printf("成功3！\n");
    }
}

void Listprint(link L) //输出链表
{
    link temp=L;
    while (temp->next!=NULL) {
        temp=temp->next;
        printf("%d",temp->data);
    }
    printf("\n");
    printf("成功4！\n");
    
}
int main()
{
    link L;
    int i;
    InitList(L);
    Creatlist_L(L);
    Listprint(L);
    Linkinsert(L, 1, 6);
    Listprint(L);
}









