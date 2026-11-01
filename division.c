#include "dll.h"

void div_operation(Dlist *head1,Dlist *tail1,Dlist *head2, Dlist *tail2,Dlist **headR, Dlist **tailR)
{
    Dlist *head3 = NULL;
    Dlist *tail3 = NULL;
    Dlist *res_head = NULL;
    Dlist *res_tail = NULL;
    Dlist *temp1 = head1;

    while(temp1!=NULL)
    {
        int ret, count=0;
        Dlist *temp2 = head2;
        insert_last(&head3, &tail3,temp1->data);
        temp1=temp1->next;
        leading_zero(&head3,&tail3);

        while(compare_lists(head3,tail3,temp2,tail2)==NORMAL)
        {
            sub_operation(tail3, tail2, &res_head, &res_tail);
            count++;
            delete_list(&head3,&tail3);
            head3 = res_head;
            tail3 = res_tail;
            res_head = NULL;
            res_tail = NULL;
            leading_zero(&head3,&tail3);
        }
        insert_last(headR,tailR,count);
    }
}