#ifndef DLL_H
#define DLL_H

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1
#define NORMAL -2
#define SWAP -3

typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}Dlist;

int create_node(Dlist **head, Dlist **tail, char *str);
int insert_last(Dlist **head,Dlist **tail, int data);
void print_list(Dlist *head,Dlist *tail);
void leading_zero(Dlist **head,Dlist **tail);
int delete_list(Dlist **head,Dlist **tail);
void print_result(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2, Dlist *headR, Dlist *tailR,char opr);
void get_list_length(Dlist *head1, Dlist *tail1,Dlist *head2, Dlist *tail2,int *list1_len,int *list2_len);
int compare_lists(Dlist *head1, Dlist *tail1,Dlist *head2, Dlist *tail2);
void add_operation(Dlist *tail1, Dlist *tail2,Dlist **headR, Dlist **tailR);
void mul_operation(Dlist *head1,Dlist *tail1,Dlist *head2, Dlist *tail2,Dlist **headR, Dlist **tailR);
void div_operation(Dlist *head1,Dlist *tail1,Dlist *head2, Dlist *tail2,Dlist **headR, Dlist **tailR);
int insert_first(Dlist **head,Dlist **tail, int data);
void sub_operation(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR);

#endif