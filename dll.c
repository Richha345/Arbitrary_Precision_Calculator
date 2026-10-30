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

void get_list_length(Dlist *head1, Dlist *tail1,Dlist *head2, Dlist *tail2,int *list1_len,int *list2_len)
{
    while(head1!=NULL)
    {
        head1=head1->next;
        (*list1_len)++;
    }
    while(head2!=NULL)
    {
        head2=head2->next;
        (*list2_len)++;
    }
}

int compare_lists(Dlist *head1, Dlist *tail1,Dlist *head2, Dlist *tail2)
{
    int list1_len=0,list2_len=0;
    get_list_length(head1,tail1,head2,tail2,&list1_len,&list2_len);
    if(list1_len>list2_len)
        return NORMAL;
    else if(list1_len<list2_len)
        return SWAP;
    else if(list1_len==list2_len)
    {
        while(head1->data==head2->data && head1!=NULL && head2!=NULL)
        {
            head1=head1->next;
            head2=head2->next;
        }
        if(head1==NULL && head2==NULL)
            return NORMAL;
        if(head1->data>head2->data)
            return NORMAL;
        else if(head1->data<head2->data)
            return SWAP;
    }
}

void print_result(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2, Dlist *headR, Dlist *tailR,char opr)
{
    print_list(head1, tail1);
    printf(" %c ",opr);
    print_list(head2, tail2);
    printf(" = ");
    print_list(headR, tailR);
    printf("\n");
}

void leading_zero(Dlist **head,Dlist **tail)
{
    while(head!=NULL && (*head)->data==0)
    {
        Dlist *temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
    }
}