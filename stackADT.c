#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
    void* dataPtr;
    struct node* link;
}STACK_NODE;

typedef struct
{
    int count;
    STACK_NODE* top;
}STACK;

//Create empty STACK
STACK* createStack(void)
{
    STACK* stack;

    stack = (STACK*)malloc(sizeof(STACK));
    if(stack)
    {
        stack->count = 0;
        stack->top = NULL;
    }

    return stack;
}

//Push
bool pushStack(STACK* stack, void* dataInPtr)
{
    STACK_NODE* newPtr;

    newPtr = (STACK_NODE*)malloc(sizeof(STACK_NODE));
    if(!newPtr)
        return false;
    newPtr->dataPtr = dataInPtr;
    
    newPtr->link = stack->top;
    stack->top = newPtr;

    (stack->count)++;
    return true;
}

//Pop stack
void* popStack(STACK* stack)
{
    void* dataOutPtr;
    STACK_NODE* temp;

    if(stack->count == 0)
        dataOutPtr = NULL;
    else
    {
        temp = stack->top;
        dataOutPtr = stack->top->dataPtr;
        stack->top = stack->top->link;
        free(temp);
        (stack->count)--;
    }
return dataOutPtr;
}

//stack top
void* stackTop(STACK* stack)
{
    if(stack->count==0)
        return NULL;
    else
        return stack->top->dataPtr;
}
//empty stack
bool emptyStack(STACK* stack)
{
    return(stack->count==0);
}

//full stack
bool fullStack(STACK* stack)
{
    STACK_NODE* temp;

    if((temp = (STACK_NODE*)malloc(sizeof(*stack->top))))
    {
        free(temp);
        return false;
    }
    return true; //malloc failed hence fullstack
}

//stack count
int stackCount(STACK* stack)
{
    return stack->count;
}
int main()
{
    STACK* st =createStack();
    pushStack(st,(int*)7);
    pushStack(st,(int*)99);
    pushStack(st,(int*)101);

    printf("Top of the stack is: %d",(int)stackTop(st));
    printf("\nCount of the stack is: %d\n",stackCount(st));

    popStack(st);
    printf("\nTop of the stack is: %d",(int)stackTop(st));
    printf("\nCount of the stack is: %d\n",stackCount(st));

    popStack(st);
    printf("\nTop of the stack is: %d",(int)stackTop(st));
    printf("\nCount of the stack is: %d\n",stackCount(st));


    popStack(st);
    printf("\nTop of the stack is: %d",(int)stackTop(st));
    printf("\nCount of the stack is: %d\n",stackCount(st));

    popStack(st);
    printf("\nTop of the stack is: %d",(int)stackTop(st));
    printf("\nCount of the stack is: %d\n",stackCount(st));


}
