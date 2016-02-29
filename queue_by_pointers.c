#include <stdio.h>
#include <stdlib.h>
#define SIZE 20
typedef int Type;
typedef struct Node
{
    Type data;
    struct Node *next;
} NODE;

typedef struct Queue
{
    struct Node *front;
    struct Node *rear;
} LINKQ;

void initq(LINKQ* queue);
void inq(LINKQ* queue,Type data);
Type outq(LINKQ* queue);
int isempty(LINKQ* queue);
void printstate(LINKQ* queue);

/********************   main  **********************/
int main()
{
    int i,datademo;  /*datademo is the out element*/
    LINKQ *qdemo = (LINKQ*)malloc(sizeof(LINKQ));
    initq(qdemo);
    for(i=0; i<SIZE; i++)
    {
        inq(qdemo,i+1);
    }
    printstate(qdemo);
    printf("Delete some element of the queue:");
    for(i=0; i<SIZE; i++)
    {
        datademo = outq(qdemo);
        printf(" %d",datademo);
    }
    printf("\n");
    printstate(qdemo);
    free(qdemo);
    return 0;
}

/*******************  implementation  ******************************/
void initq(LINKQ *q)
{
    NODE *node = (NODE*)malloc(sizeof(NODE));
    node->data = 0;   /*the first element in the queue is 0*/
    node->next = NULL;  /*the domain of next is null*/
    q->front = node;
    q->rear = node;
}
void inq(LINKQ *q,Type data)
{
    NODE *node = (NODE*)malloc(sizeof(NODE));
    node->data = data;
    node->next = NULL;
    q->rear->next = node;
    q->rear = node;   /*the rear is the new element*/
}
Type outq(LINKQ *q)
{
    Type data;
    NODE *help = (NODE*)malloc(sizeof(NODE));
    if(!isempty(q))    /* when the queue isn't empty */
    {
        help = q->front->next;  /* assistant,points to the
        next element of the front */
        data = q->front->data;
        free(q->front);
        q->front = help;
        return data;
    }
    else
    {
        printf("\nError: the queue is empty!\n");
        exit(1);
    }
}
int isempty(LINKQ *q)    /*empty or not*/
{
    return (q->front == q->rear);
}
void printstate(LINKQ *q)
{
    NODE* cur = (NODE*)malloc(sizeof(NODE));
    int i=0;
    cur = q->front;
    printf("The element of the queue: ");
    while(cur!=NULL)
    {
        printf(" %d",cur->data);/* print out the element of queue */
        cur = cur->next;
        i++;
    }
    printf("\nThe count of the element is %d.\n",i);
    free(cur);
}
