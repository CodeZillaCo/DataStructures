#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
class doublelist
{
private:
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *head;
struct node *tail;
public:
//CONSTRUCTORS
doublelist()
{
    head=NULL;
    tail=NULL;
}
//FUNCTIONS
int insatbeg(int);
int insatend(int);
int insatpos(int,int);
int delatbeg();
int delatpos(int);
int delatend();
void search(int);
void display();
};
int main()
{
    //CLASS NAME
    doublelist list;
    int choice,choice1,choice2,val,pos,val1;
    while(true)
    {
        printf("\nMENU");
        printf("\n1.INSERTION");
        printf("\n2.DELETION");
        printf("\n3.SEARCHING");
        printf("\n4.DISPLAY");
        printf("\n5.EXIT");
        printf("\n\n");
        printf("Enter the choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case(1):
        {
            printf("\nMENU");
            printf("\n1.At the beginning");
            printf("\n2.At a position");
            printf("\n3.At the end");
            printf("\nEnter the choice:");
            scanf("%d",&choice1);
            switch (choice1)
            {
                case(1):
                {
                    printf("\nEnter the element to be inserted:");
                    scanf("%d",&val);
                    if (list.insatbeg(val)==1)
                    {
                        printf("\nThe element has been successfully inserted");
                    }
                    break;
                }
                case(2):
                {
                    printf("\nEnter the element to be inserted:");
                    scanf("%d",&val);    
                    printf("\nEnter the position:");
                    scanf("%d",&pos);                
                    int s=list.insatpos(val,pos);
                    if (s==1)
                    {
                        printf("\nThe element has been successfully inserted");
                    }
                    else if(s==-1)
                    {
                        printf("\nThe postion is lesser than zero");
                    }
                    else if(s==0)
                    {
                        printf("\nThe list is empty");
                    }
                    else if(s==-2)
                    {
                        printf("\nThe position given is greater than the length of the list");
                    }
                    break;
                }
                case(3):
                {
                    printf("\nEnter the element to be inserted:");
                    scanf("%d",&val);
                    if (list.insatend(val)==1)
                    {
                        printf("\nThe element has been successfully inserted");
                    }
                    break;
                }
            }
            break;
        }
        case 2:
        {
            printf("\nMENU");
            printf("\n1.At beginning");
            printf("\n2.At a position");
            printf("\n3.At end");
            printf("\nEnter the choice:");
            scanf("%d",&choice2);
            switch(choice2)
            {
                case 1:
                {
                    if(list.delatbeg()==1)
                    {
                        printf("\nDeleted successfully");
                    }
                    else
                    {
                        printf("\nThe lsit is empty");
                    }
                    break;
                }
                case 2:
                {
                    printf("\nEnter the position:");
                    scanf("%d",&pos);               
                    int p=list.delatpos(pos);
                    if(p==1)
                    {
                        printf("\nDeleted successfully");
                    }
                    else if(p==0)
                    {
                        printf("\nThe list is empty");
                    }
                    else if(p==-1)
                    {
                        printf("\nThe postion is lesser than zero");
                    }
                    else if(p==-2)
                    {
                        printf("\nThe position given is greater than the length of the list");
                    }
                    break;
                }
                case 3:
                {
                    if(list.delatend()==1)
                    {
                        printf("\nDeleted successfully");
                    }
                    else
                    {
                        printf("\nThe list is empty");
                    }
                    break;
                }
            }
            break;
        }
        case 3:
        {
            printf("\nEnter the value to be searched:");
            scanf("%d",&val1);               
            list.search(val1);
            break;
        }
        case 4:
        {
            printf("The values of the list:");
            printf("\n");
            list.display();
            break;
        }
        case 5:
        {
            return 0;
        }
        default:
        {
            printf("Invalid choice");
            break;
        }
        }
    }
}
//METHOD TO INSERT AT THE BEGINNING
//TIME COMPLEXITY : O(1)
int doublelist::insatbeg(int value)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    if(head==NULL)
    {
        newnode->next=newnode;
        newnode->prev=newnode;
        head=newnode;

    }
    else
    {
        head->prev->next=newnode;
        newnode->prev=head->prev;
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
    return 1;
}
//METHOD TO INSERT AT THE END
//TIME COMPLEXITY : O(1)
int doublelist::insatend(int value)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    if(head==NULL)
    {
        newnode->next=newnode;
        newnode->prev=newnode;
        head=newnode;      
    }
    else
    {
        newnode->prev=head;
        newnode->next=head->next;
        head->next->prev=newnode;
        head->next=newnode;
        head=newnode;

    }
    return 1;
}
//METHOD TO INSERT AT A POSITION
//TIME COMPLEXITY : O(n)
int doublelist::insatpos(int value, int pos)
{
    struct node *temp=head;
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;  
    if(pos<0)
    {
        return -1;
    }
    else if(head==NULL)
    {
        return 0;
    }
    else
    {
        for(int i=0;i<pos;i++)
        {
            if(temp==NULL)
            {
                return -2;
            }
            else
            {
                temp=temp->next;
            }
        }
        newnode->prev=temp->prev;
        temp->prev->next=newnode;
        temp->prev=newnode;
        newnode->next=temp;
        head=newnode;
        return 1;
    }
}
//METHOD TO DELETE AT THE BEGINNING
//TIME COMPLEXITY : O(1)
int doublelist::delatbeg()
{
    struct node *temp=head;
    if(head==NULL)
    {
        return 0;
    }
    else if(temp->next==temp && temp->prev==temp)
    {
        free(temp);
        return 1;
    }
    else
    {
        temp->next->prev=temp->prev;
        temp->prev->next=temp->next;
        head=temp->next;
        free(temp);
        return 1;
    }
}
//METHOD TO DELETE AT THE POSITION
//TIME COMPLEXITY : O(n)
int doublelist::delatpos(int pos)
{
    struct node *temp=head;
    if(head==NULL)
    {
        return 0;
    }
    else if(pos<0)
    {
        return -1;
    }
    else
    {
        for(int i=0;i<pos;i++)
        {
            if(temp==NULL)
            {
                return -2;
            }
            else
            {
                temp=temp->next;
            }
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        if(temp->next==NULL)
        {
            head=temp->prev; 
        }
        else if(temp->prev==NULL)
        {
            head=temp->next;
        }
        else if(temp->next==NULL && temp->prev==NULL)
        {
            head=NULL;
        }
        else
        {
            head=temp->next;
        }
        free(temp);
        return 1;
    }
}
//METHOD TO DELETE AT THE END
//TIME COMPLEXITY : O(1)
int doublelist::delatend()
{
    struct node *temp=head;
    if(head==NULL)
    {
        return 0;
    }
    else if(temp->next==temp && temp->prev==temp)
    {
        free(temp);
        return 1;
    }
    else
    {
        temp->prev->next=temp->next;
        temp->prev->prev=temp->prev;
        head=temp->next;
        free(temp);
        return 1;
    }
}
//METHOD FOR SEARCHING
//TIME COMPLEXITY : O(n)
void doublelist::search(int val)
{
    int flag=0;
    int count=1;
    struct node *temp=head;
    if(head==NULL)
    {
        printf("\nThe list is empty");
    }
    else
    {
        while(count>0 && temp!=NULL)
        {
            if(temp->data==val)
            {
                printf("\nThe list is found at %d position",count);
                flag=1;
                break;
            }
            count++;
            temp=temp->next;
        }
        if(flag==0)
        {
            printf("\nThe element is not present in the list");
        }
    }
}
//METHOD FOR DISPLAYING THE LIST
//TIME COMPLEXITY : O(n)
void doublelist::display()
{
    if(head==NULL)
    {
        printf("The list is empty");
    }
    else
    {
        struct node *temp=head->next;
        printf("\t%d",head->data);
        while(temp!=head)
        {
            printf("\t%d",temp->data);
            temp=temp->next;
        }
    }
}

