#include"dll.h"

void sub_operation(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR)
{
    Dlist *temp1 = tail1;
    Dlist *temp2 = tail2;

    int data,ret,borrow = 0;

    while (temp1 != NULL || temp2 != NULL)
    {
        if(temp1 != NULL && temp2 != NULL)
        {
             if(temp1->data<temp2->data)
             {
                data = (temp1->data+10)-temp2->data-borrow;
                borrow=1;
             }
             else
             {
                data = temp1->data-temp2->data-borrow;
                borrow=0;
             }
             insert_first(headR,tailR,data%10);
             temp1=temp1->prev;
             temp2=temp2->prev;
        }
        else if(temp1 != NULL && temp2 == NULL)
        {
            data=temp1->data-borrow;
            if(data<0)
            {
                data=data+10;
                borrow = 1;
            }
            else
                borrow = 0;
            temp1 = temp1->prev;
            insert_first(headR,tailR,data%10);
        }
        else if(temp1 == NULL && temp2 != NULL)
        {
            data=temp2->data-borrow;
            if(data<0)
            {
                data=data+10;
                borrow = 1;
            }
            else
                borrow = 0;
            temp2 = temp2->prev;
            insert_first(headR,tailR,data%10);
        }
    }
}