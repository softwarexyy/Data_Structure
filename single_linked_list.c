/*****************  头插法构造链表以及插入、查找、删除结点  ********************/

#include <stdio.h>
#include <stdlib.h>
typedef struct Linklist
{
    int data;
    struct Linklist *next;
} NODE;

void insertnode(NODE *,int *);/*插入结点*/
void init(NODE *,NODE *,int *);/*返回链表除头结点外的结点个数*/
void showlist(NODE *,int );/*显示链表内信息*/
void deletenode(int *,NODE *);/*删除结点*/
int searchnode(int,NODE *); /*查找结点*/
int main()
{
    NODE *p,*first;/*p是一开始定义的头指针，
                   first始终是头指针*/
    int nodeNum=0;/*i记载除头结点外的结点数*/
    int searchAns;
    if((first=(NODE *)malloc(sizeof(NODE)))==(NODE *)NULL)
    {
        printf("Failed to allocate.\n");
        exit(1);
    }
    p=first;
    init(p,first,&nodeNum);
    showlist(first,nodeNum);
    deletenode(&nodeNum,first);
    showlist(first,nodeNum);
    searchAns=searchnode(nodeNum,first);
    free(first);
    return 0;
}


void insertnode(NODE *p,int *nodeNum) /*插入结点*/
{
    NODE *newnode;
    if((newnode=(NODE *)malloc(sizeof(NODE)))==(NODE *)NULL)
    {
        printf("Failed to allocate.\n");
        exit(1);
    }
    printf("输入结点数据：");
    scanf("%d",&(newnode->data));
    newnode->next=p->next;
    p->next=newnode;
    (*nodeNum)++;
}
void init(NODE *cur,NODE *first,int *nodeNum)
{
    char rspn;/*是否继续输入结点*/
    printf("输入结点吗(y/n):");
    scanf("%c",&rspn);
    while(rspn=='y')
    {
        insertnode(cur,nodeNum);
        cur=cur->next;
        getchar();/*获取上次输入结束留下的回车符*/
        printf("还输入结点吗(y/n):");
        scanf("%c",&rspn);
    }
}
void showlist(NODE *first,int nodeNum)
{
    int i;/*用于读取链表时的游标*/
    NODE *cur;
    cur=first;
    printf("除头结点外共有%d个结点\n",nodeNum);
    for(i=0; i<nodeNum; i++)
    {
        printf("结点%d的信息是：",i+1);
        printf("%d\n",cur->next->data);
        cur=cur->next;/*每读取一个结点，s往后移动一位*/
    }
}
void deletenode(int *nodeNum,NODE *first)
{
    int i;//待删除的是第i个结点
    int j;
    NODE *cur,*del;//cur是游标，del指向待删结点
    cur=first;
    printf("要删除第几个结点？请输入：");
    scanf("%d",&i);
    if(i>*nodeNum)
    {
        printf("对不起，您输入的数据有误。\n");
        exit(1);
    }
    for(j=1; j<i; j++)
        cur=cur->next;
    del=cur->next;
    cur->next=cur->next->next;
    free(del);
    (*nodeNum)--;
}
int searchnode(int nodeNum,NODE *first)
{
    int i;/*要删除的是第i个结点*/
    int j;
    NODE *cur;/*游标，依次往后直到指向第i个结点*/
    cur=first;
    printf("要查询第几个结点？请输入：");
    scanf("%d",&i);
    if(i>nodeNum)
    {
        printf("对不起，您输入的数据有误。\n");
        exit(1);
    }
    for(j=0; j<i; j++)
    {
        cur=cur->next;
    }
    printf("您要寻找的结点信息是：%d\n",cur->data);
    return (cur->data);
}
