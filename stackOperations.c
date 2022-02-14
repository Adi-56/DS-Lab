//Adithya Praveen
//5
#include<stdio.h>
int stack[100], top, size;

void push();
void pop();
void display();
void menu();

//To push into the stack
void push()
{
    int item;
    if(top>=size-1)
        printf("\n STACK OVERFLOW!!");
    else
    {
        top++;
        printf("\n Enter the element: ");
        scanf("%d",&item);
        stack[top] = item;
    }
    
}

//To pop from the stack
void pop()
{
    if(top == -1)
        printf("\n STACK UNDERFLOW!!");
    else
    {
        printf("\n Deleted element: %d",stack[top]);
        top--;
        printf("\n Current stack is: ");
        display();
    }
}

void display()
{
    if(top>=0)
    {
        printf("\n Elements in the stack are: \n");
        for(int i=top;i>=0;i--)
            printf("%d\n",stack[i]);
    }
    else
        printf("\n No elements present in the stack!!");
}

//To display the menu
void menu()
{
    int ch;
    do
    {
        printf("\n \n ##################STACK OPERATIONS#######################\n\n \t1)Push \n \t2)Pop \n \t3)Display \n \t4)Exit \n\nEnter the choice from the above options!");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: break;
            default: printf("Invalid option!!Try again");
                    break;
        }
    }while(ch!=4);
   
}

int main()
{
    printf("Enter the size of the stack(max 100): ");
    scanf("%d",&size);
    top = -1;
    menu();
}
