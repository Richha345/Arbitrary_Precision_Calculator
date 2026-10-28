#include "dll.h"

void print_list(Dlist *head,Dlist *tail)
{
    printf("head -> ");
    while(head!=NULL)
    {
        printf(" %d <-",head->data);
        head=head->next;
        if(head!=NULL)
            printf("> ");
    }
    printf(" tail\n");
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
    Dlist *head3=NULL;
    Dlist *tail3=NULL;
    
    create_node(&head1, &tail1, argv[1]);
    print_list(head1, tail1);

    create_node(&head2, &tail2, argv[3]);
    print_list(head2, tail2);

    switch(argv[2][0])
    {
        case '+' :
        add_operation(tail1, tail2, &head3, &tail3);
        break;

        case '-' :
        
        break;

        case '*' :
        
        break;

        case '/' :
        
        break;

        default:
        printf("Invalid Operator\n");
    }
    print_list(head3, tail3);
    return 0;
}