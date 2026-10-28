#include "dll.h"
int create_node(Dlist **head, Dlist **tail, char *str)
{
    for(int i=0;str[i]!=0;i++)
    {
        int data=str[i]-48;
        insert_last(head,tail,data);
    }
    return SUCCESS;
}

int insert_last(Dlist **head,Dlist **tail, int data)
{
    if(*head==NULL && *tail==NULL)
    {
        Dlist *newnode=malloc(sizeof(Dlist));
        if(newnode==NULL)
        {
            return FAILURE;
        }
        newnode->data=data;
        newnode->prev=NULL;
        newnode->next=NULL;
        *head=newnode;
        *tail=newnode;

        return SUCCESS;
    }
    Dlist *newnode=malloc(sizeof(Dlist));
    if(newnode==NULL)
    {
        return FAILURE;
    }
    newnode->data=data;
    newnode->prev=*tail;
    newnode->next=NULL;
    (*tail)->next=newnode;
    *tail=newnode;
    return SUCCESS;
}

int insert_first(Dlist **head,Dlist **tail, int data)
{
    if(*head==NULL && *tail==NULL)
    {
        Dlist *newnode=malloc(sizeof(Dlist));
        if(newnode==NULL)
        {
            return FAILURE;
        }
        newnode->data=data;
        newnode->prev=NULL;
        newnode->next=NULL;
        *head=newnode;
        *tail=newnode;

        return SUCCESS;
    }
    Dlist *newnode=malloc(sizeof(Dlist));
    if(newnode==NULL)
    {
        return FAILURE;
    }
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=*head;
    (*head)->prev=newnode;
    *head=newnode;
    return SUCCESS;
}


void add_operation(Dlist *tail1, Dlist *tail2, Dlist **head3, Dlist **tail3)
{
    int carry=0,sum=0;
    while(tail1!=NULL || tail2!=NULL || carry!=0)
    {
        sum=carry;
        if(tail1!=NULL)
        {
            sum=sum+tail1->data;
            tail1=tail1->prev;
        }

        if(tail2!=NULL)
        {
            sum=sum+tail2->data;
            tail2=tail2->prev;
        }

        carry=sum/10;
        insert_first(head3,tail3,sum%10);
    }

}