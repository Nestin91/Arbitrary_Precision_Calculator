#ifndef APC_H
#define APC_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct node
{
	struct node *prev;
	int data;
	struct node *next;
}Dlist;

/* Include the prototypes here */

/* Validation Functions */
int validate_operand(char *str);

int read_and_validate_args(int argc, char *argv[]);

/* Arithmetic Operations */
/* Addition */
int addition(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

/* Subtraction*/
int subtraction(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

/* Multiplication*/
int multiplication(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

/* Division */
int division(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);


/* List Manipulation */
/* To insert the element at first */
int dl_insert_first(Dlist **head, Dlist **tail, int data);

/* To insert the element at last */
int dl_insert_last(Dlist **head, Dlist **tail, int data);

/* Compare 2 operands*/
int compare(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2);

/* Store the operands into the list */
int digit_to_list(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *argv[]);

/* Delete a list */
int dl_delete_list(Dlist **head, Dlist **tail);

/* Print the list */
void print_list(Dlist *head);

#endif
