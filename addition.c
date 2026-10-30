#include"dll.h"

void add_operation(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR)
{
    Dlist *temp1 = tail1;
    Dlist *temp2 = tail2;
    int carry = 0,data;

    while (temp1 != NULL || temp2 != NULL)
    {
        if(temp1 != NULL && temp2 != NULL)
        {
            data = temp1->data+temp2->data+carry;
            carry=data/10;
            temp1=temp1->prev;
            temp2=temp2->prev;
            insert_first(headR,tailR,data%10);
        }
        else if(temp1 != NULL && temp2 == NULL)
        {
            data = temp1->data+carry;
            carry=data/10;
            temp1=temp1->prev;
            insert_first(headR,tailR,data%10);
        }
        else if(temp1 == NULL && temp2 != NULL)
        {
            data = temp2->data+carry;
            carry=data/10;
            temp2=temp2->prev;
            insert_first(headR,tailR,data%10);
        }
    }
    if(carry==1)
        insert_first(headR,tailR,carry);

}
