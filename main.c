#include "dll.h"

void print_list(Dlist *head,Dlist *tail)
{
    if(head->data == '-')
    {
        printf("%c",'-');
        head=head->next;
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
    

    create_node(&head2, &tail2, argv[3]);

    switch(argv[2][0])
    {
        case '+' :
            add_operation(tail1, tail2, &headR, &tailR);
            print_result(head1,tail1,head2,tail2,headR,tailR,argv[2][0]);
        break;

        case '-' :
            if((ret = compare_lists(head1,tail1,head2,tail2))==NORMAL)  
                sub_operation(tail1, tail2, &headR, &tailR);
            else if(ret == SWAP)
            {
                sub_operation(tail2, tail1, &headR, &tailR);
                insert_first(&headR,&tailR,'-');
            }
            print_result(head1,tail1,head2,tail2,headR,tailR,argv[2][0]);
        break;

        case 'x' :
        case 'X' :
            mul_operation(head1,tail1,head2,tail2,&headR,&tailR);
        break;

        case '/' :
            div_operation(head1,tail1,head2,tail2,&headR,&tailR);
            print_result(head1,tail1,head2,tail2,headR,tailR,argv[2][0]);
        break;

        default:
        printf("Invalid Operator\n");
    }
    return 0;
}