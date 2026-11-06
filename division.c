#include"dll.h"
int div_operation(Dlist *head1,Dlist *tail1, Dlist *head2,Dlist *tail2, Dlist **headR,Dlist **tailR)
{
    Dlist *head3=NULL;
    Dlist *tail3=NULL;
    Dlist *res_head=NULL;
    Dlist *res_tail=NULL;
    Dlist *temp1=head1;

    int count=0;

    // Division by zero
    Dlist *temp2=head2;
    while(temp2!=NULL)
    {
        if(temp2->data!=0)
        {
            break;
        }
        temp2=temp2->next;
    }

    if(temp2==NULL)
    {
        printf("ERROR: Division by ZERO not possible\n");
        return FAILURE;
    }

    while(temp1!=NULL)
    {
        insert_last(&head3,&tail3,temp1->data);
        temp1=temp1->next;

        leading_zero(&head3,&tail3);

        count=0;

        while(compare_lists(head3,tail3,head2,tail2)==NORMAL)
        {
            sub_operation(tail3,tail2,&res_head,&res_tail);

            count++;

            delete_list(&head3,&tail3);

            head3=res_head;
            tail3=res_tail;

            res_head=NULL;
            res_tail=NULL;

            leading_zero(&head3,&tail3);
        }

        insert_last(headR,tailR,count);
    }

    leading_zero(headR,tailR);

    return SUCCESS;
}