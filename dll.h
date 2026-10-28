#ifndef DLL_H
#define DLL_H

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}Dlist;

int create_node(Dlist **head, Dlist **tail, char *str);
int insert_last(Dlist **head,Dlist **tail, int data);
void print_list(Dlist *head,Dlist *tail);
void add_operation(Dlist *tail1, Dlist *tail2,Dlist **head3, Dlist **tail3);
int insert_first(Dlist **head,Dlist **tail, int data);

#endif