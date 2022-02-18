//FATIMA ISMAIL
//TLY20CS028
//PROGRAM TO IMPLEMENT SINGLE QUEUE USING ARRAY 
//10/12/21

#include <stdio.h>
#define max 5
int front=-1,rear=-1,A[max];

void enqueue();
void dequeue();
void display();

int main()
{
   int flag=0,ch;
   while(flag==0)
   {
       printf("\n**********MENU**********\n");
       printf("1.Enqueue operation()\n2.Dequeue operation\n3.Display\n4.Exit\n");
       scanf("%d",&ch);
       switch(ch)
       {
           case 1: enqueue();
                    break;
           case 2: dequeue();
                    break;
           case 3: printf("The queue is:\n");
                   display();
                    break;
           case 4: printf("\nOPERATION COMPLETED\n");
                    flag=1;
                    break;
           default:printf("\nINVALID CHOICE\n");
       }
   }
}
void enqueue()
{
    int item;
    if(rear==max-1)
    printf("\nOVERFLOW\n");
    else 
    {
        if(rear==-1 && front==-1)
        {
            front=0;
        }
        printf("Enter the element to be inserted:\n");
        scanf("%d",&item);
        rear=rear+1;
        A[rear]=item;
    }
}
void dequeue()
{
    int item;
    if(front==-1 || front>rear)
    printf("\nUNDERFLOW\n");
    else
    {
        item=A[front];
        printf("The deleted item is :%d ",item);
        front=front+1;
    }
}
void display()
{
    int i;
    for(i=front;i<=rear;i++)
    printf("%d\t",A[i]);
}
