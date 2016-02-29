//Use static array(no pointers):
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
    typedef int Type;
    typedef struct stack
{
    int top;
    int bottom;
    int count;  /* the count of the stack elements */
    Type content[SIZE];
} Stack;
void initstack(Stack *sdemo);
void push(Stack *sdemo,Type data);
Type pop(Stack *sdemo);
int isempty(Stack *sdemo);
int isfull(Stack *sdemo);
void printmsg(Stack *sdemo); /* show the message of the current stack */
int main()
{
    int i;
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if(stack == NULL)
    {
        printf("Failed to allocate memory ...\n");
        exit(1);
    }
    initstack(stack);
    printmsg(stack);

    for(i=0; i<SIZE-1; i++)
        push(stack,i+1);
    printmsg(stack);
    for(i=0; i<SIZE-2; i++)
        pop(stack);
    printmsg(stack);

    free(stack);
    return 0;
}
void initstack(Stack *sdemo)
{
    int i;
    sdemo->count = 0;
    sdemo->top = 0;
    sdemo->bottom = 0;
    for(i=0; i<SIZE; i++)
        sdemo->content[i] = 0;
}
void push(Stack *sdemo,Type data)
{
    if(!isfull(sdemo))
    {
        sdemo->content[++sdemo->top] = data;
        sdemo->count++;
    }
    else
    {
        printf("Error: The stack is full,can not push elements.\n");
        exit(1);
    }
}
Type pop(Stack *sdemo)
{
    Type data;
    if(!isempty(sdemo))
    {
        data = sdemo->content[--sdemo->top];
        sdemo->count--;
        return data;
    }
    else
    {
        printf("Error: The stack is empty,can not pop elements.\n");
        exit(1);
    }
}
int isempty(Stack *sdemo)
{
    return sdemo->top == 0;
}
int isfull(Stack *sdemo)
{
    return sdemo->top == SIZE-1;
}
void printmsg(Stack *sdemo)
{
    int i;
    printf("The count of the elements in the stack is: %d.\n",sdemo->count);
    printf("The elements in the stack are: ");
    for(i=1; i<(sdemo->count+1); i++)
    {
        printf("%d ",sdemo->content[i]);
    }
    printf("\n");
}
