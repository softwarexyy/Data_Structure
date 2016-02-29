//Use dynamic array(use pointers):
#include <stdio.h>
#include <stdlib.h>
typedef int Type;
typedef struct node
{
    Type data;
    struct node *next;
} Node;

typedef struct stack
{
    struct node *top;
    struct node *bottom;
} LinkStack;

void initstack(LinkStack *sdemo);
void push(LinkStack *sdemo,Type data);
Type pop(LinkStack *sdemo);
int isempty(LinkStack *sdemo);
void printmsg(LinkStack *sdemo); /* show the message about the stack */

/**************** driver: method 'main' ******************/
int main()
{
    int i;
    LinkStack *stack = (LinkStack *)malloc(sizeof(LinkStack));
    initstack(stack);
    printf("After initial:\n");
    printmsg(stack);
    printf("\nAfter push elements:\n");
    for(i=0; i<10; i++) /* test the method 'push'*/
        push(stack,i+1);
    printmsg(stack);
    printf("\nAfter pop elements:\n");
    printf("The elements poped is: "); /*test the method 'pop'*/
    for(i=0; i<10; i++)
        printf("%d ",pop(stack));
    printf("\n");
    printmsg(stack);
    return 0;
}

/************ the realization of the methods *************/
void initstack(LinkStack *sdemo)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if(node == (Node *)NULL)
    {
        printf("Failed to allocate memory.\n");
        exit(1);
    }
    node->data = 0;
    node->next = NULL;
    sdemo->top = node;
    sdemo->bottom = node;
}
void push(LinkStack *sdemo,Type data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if(node == (Node *)NULL)
    {
        printf("Failed to allocate memory.\n");
        exit(1);
    }
    node->data = data;
    node->next = sdemo->top->next;
    sdemo->top->next = node;
    sdemo->top = node;
}
Type pop(LinkStack *sdemo)
{
    Type data;
    Node *helper = (Node *)malloc(sizeof(Node));
    if(helper == (Node *)NULL)
    {
        printf("Failed to allocate memory.\n");
        exit(1);
    }
    if(!isempty(sdemo))
    {
        data = sdemo->top->data;
        helper = sdemo->bottom;
        while(helper->next != sdemo->top)
            helper = helper->next;
        sdemo->top = helper;
        free(sdemo->top->next);
        return data;
    }
    else
    {
        printf("Error: The stack is empty,can not pop.\n");
        exit(1);
    }
}
int isempty(LinkStack *sdemo)
{
    return sdemo->bottom == sdemo->top;
}
void printmsg(LinkStack *sdemo)
{
    int i=0;
    Node *helper = (Node *)malloc(sizeof(Node));
    if(helper ==(Node *)NULL)
    {
        printf("Failed to allocate memory.\n");
        exit(1);
    }
    helper = sdemo->bottom;
    printf("The elements of the stack are:");
    while(helper != sdemo->top)
    {
        helper = helper->next;
        printf("%d ",helper->data);
        i++;
    }
    printf("\nThe count of the elements is: %d .\n",i);
}
