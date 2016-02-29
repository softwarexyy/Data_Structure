#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
typedef struct Queuedemo
{
    int front;
    int rear;
    int count;/*队列元素个数*/
    int q[SIZE];
} queue;

void initqueue(queue *q_demo);
void inqueue(queue *q_demo,int data);
int outqueue(queue *q_demo);
int isfull(queue *q_demo);
int isempty(queue *q_demo);
void printmsg(queue *q_demo);/*打印队列状态信息*/

///////////////// main()  /////////////////////////////
int main()
{
    int data;
    queue *q_demo = (queue*)malloc(sizeof(queue));
    initqueue(q_demo);
    printmsg(q_demo);
    inqueue(q_demo,10);
    printmsg(q_demo);
    data = outqueue(q_demo);
    printmsg(q_demo);
    printf("%d\n",data);
    free(q_demo);
    return 0;
}

/*****************实现*****************/
/*初始化*/
void initqueue(queue *q_demo)
{
    int i;
    q_demo->count = 0;
    q_demo->front = 0;
    q_demo->rear = 0;
    for(i=0; i<SIZE; i++)
        q_demo->q[i] = 0;
}
/*进队列*/
void inqueue(queue *q_demo,int data)
{
    if(!isfull(q_demo))
    {
        (q_demo->count)++;
        q_demo->q[(q_demo->count-1)%SIZE] = data;
        q_demo->rear = (++q_demo->rear)%SIZE;
    }
    else
    {
        printf("队列已满,入队操作失败.\n");
        exit(1);
    }
}
/*出队列*/
int outqueue(queue *q_demo)
{
    int data;
    if(!isempty(q_demo))
    {
        data = q_demo->q[(q_demo->count-1)%SIZE];
        q_demo->q[(q_demo->count-1)%SIZE] = 0;
        (q_demo->count)--;
        q_demo->front = (++q_demo->front)%SIZE;
    }
    else
    {
        printf("队列为空,出队列操作失败.\n");
        exit(1);
    }
    return data;
}
/*判空*/
int isempty(queue *q_demo)
{
    if(q_demo->count==0)
        return 1;
    else
        return 0;
}
/*判满*/
int isfull(queue *q_demo)
{
    if(q_demo->count==SIZE)
        return 1;
    else
        return 0;
}
void printmsg(queue *q_demo)
{
    int i;
    printf("队列状态：\n");
    printf("队列有%d个元素\n",q_demo->count);
    for(i=0; i<SIZE; i++)
        printf("%-3d",q_demo->q[i]);
    printf("\n");
}
