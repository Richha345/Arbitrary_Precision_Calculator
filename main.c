#include "dll.h"

void print_list(Dlist *head,Dlist *tail)
{
    if((head->data == '+' || head->data =='-') && head!=NULL && head->next->data==0 && head->next->next ==NULL)
    {
        printf("0 ");
        return ;
    }
    if(head->data == '-' ||head->data == '+')
    {
        printf("%c",head->data);
        head = head->next;
        head->prev=NULL;
    }
    leading_zero(&head,&tail);
    while(head!=NULL)
    {
        printf("%d",head->data);
        head=head->next;
    }
}
int main(int argc, char *argv[])
{
    if(argc!=4)
    {
        printf("Invalid input Argument\n");
        return FAILURE;
    }
    Dlist *head1=NULL;
    Dlist *tail1=NULL;
    Dlist *head2=NULL;
    Dlist *tail2=NULL;
    Dlist *headR=NULL;
    Dlist *tailR=NULL;
    int ret;
    create_node(&head1, &tail1, argv[1]);
    print_list(head1, tail1);
    printf(" %c ",argv[2][0]);

    create_node(&head2, &tail2, argv[3]);
    print_list(head2, tail2);
    printf(" = ");

    char sign = '+';
    char opr = operation_type(&head1,&tail1,&head2,&tail2,argv[2][0],&sign);
    switch(opr)
    {
        case '+' :
            add_operation(tail1, tail2, &headR, &tailR);
            if(sign == '-')
                insert_first(&headR,&tailR,sign);

            print_list(headR,tailR);
        break;

        case '-' :

            if((ret = compare_lists(head1,tail1,head2,tail2))==NORMAL)  
                sub_operation(tail1, tail2, &headR, &tailR);
            else
            {
                sub_operation(tail2, tail1, &headR, &tailR);
            }
            if(sign == '-')
                insert_first(&headR,&tailR,sign);
            print_list(headR, tailR);
        break;

        case 'x' :
        case 'X' :
            mul_operation(head1,tail1,head2,tail2,&headR,&tailR,sign);
        break;

        case '/' :
            if(div_operation(head1,tail1,head2,tail2,&headR,&tailR)==FAILURE)
                return FAILURE;

            if(sign == '-')
                insert_first(&headR,&tailR,sign);
            print_list(headR, tailR);
        break;

        default:
        printf("Invalid Operator\n");
    }
    printf("\n");
    return 0;
}