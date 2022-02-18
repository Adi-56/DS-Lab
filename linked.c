#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*link;
};
struct node*head=NULL;

void InsertAtFront(){
    int item;
    struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enterr data item");
    scanf("%d",&item);
    temp->data=item;
    temp->link=head;
    head=temp;
    
               }
               
void InsertAtEnd(){
    int item;
    struct node*ptr,*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    ptr=head;
    while(ptr->link!=NULL){
        ptr=ptr->link;}
    printf("enterr data item");
    scanf("%d",&item);
     ptr->link=temp;
     temp->data=item;
     
        }

 void InsertAtAnyPosition(){
     struct node*temp,*ptr;
     int key,item;
     printf("enter key");
     scanf("%d",&key);
     temp=(struct node*)malloc(sizeof(struct node));
     ptr=head;
     while(ptr->link!=NULL&& ptr->data!=key){
         ptr=ptr->link; }
    if(ptr->link==NULL)
             printf("no key found");
    else{
        printf("enter data");
        scanf("%d",&item);
        temp->data=item;
        temp->link=ptr->link;
        ptr->link=temp;
    }
     
 }  
    
    void DeleteAtFront(){
         if(head==NULL)
        printf("List is empty");
    else{
        head=head->link;
    }
        
    }
    void DeleteAtEnd(){
        struct node*prev,*current;
         if(head==NULL)
        printf("List is empty");
        else if(head->link==NULL){
            head=NULL;
        }
         else{
        current=head;
        while(current->link!=NULL){
               prev=current;
              current=current->link;
             }
        prev->link=NULL;

    }}
    
    void DeleteAtAnyPosition(){
        struct node*current,*prev;
        int key;
        current=head;
        prev=head;
        printf("enter key");
        scanf("%d",&key);
        while(current->data!=key && current->link!=NULL){
             prev=current;
            current=current->link;
        }
        if(current->data==key&& current->link!=NULL)
                     prev->link=current->link;
        else if(current->data==key&& current->link==NULL)   
                   current=NULL;
        else{
            printf("no key found");
        }
        
        
    }
    
  void display(){
     struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
     if(head==NULL)
        printf("List is empty");
    else{
        temp=head;
        printf("list is :");
        while(temp!=NULL){
            printf("%d",temp->data);
            temp=temp->link;
        }}}
  int main(){
    int n;
    while(n!=8){
        
    printf("        \nLIST OPERATIONS         \nenter\n 1--InsertAtFront \n 2--InsertAtEnd\n3--InsertAtAnyPosition\n4--DeleteAtFront\n5--DeleteAtEnd\n6--DeleteAtAnyPosition\n7--Display\n8--exit\n");
    scanf("%d",&n);
    switch(n){
        case 1:
           InsertAtFront();
           break;
        case 2:
            InsertAtEnd();
            break;
        case 3:
            InsertAtAnyPosition();
            break;
        case 4:DeleteAtFront();
            break;
        case 5:
              DeleteAtEnd();
              break;
        case 6:
             DeleteAtAnyPosition();
             break;
        case 7:
           display();
           break;
        
        case 8:
           n=8;
           printf("operation completed");
           break;
      
    }}
    return 0; }
