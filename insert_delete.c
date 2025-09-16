#include "apc.h"

int dl_insert_first(Dlist **head, Dlist **tail, int data)
{
    /* Create new node */
    Dlist *new = malloc(sizeof(Dlist));
    
    /* Validate node */
    if(new == NULL)
    {
        printf("ERROR: Memory not allocated\n");
        return FAILURE;
    }
    
    /* Update */
    new -> data = data;
    new -> prev = NULL;
    new -> next = *head;
    
    /* For empty list */
    if(*head == NULL)
    {
        *head = new;
        *tail = new;
        return SUCCESS;
    }
    
    (*head) -> prev = new;
    *head = new;
    
    return SUCCESS;
}

int dl_insert_last(Dlist **head, Dlist **tail, int data)
{
    /* Create new node */
    Dlist *new = malloc(sizeof(Dlist));
    
    /* Validate node */
    if(new == NULL)
    {
        printf("ERROR: Memory not allocated\n");
        return FAILURE;
    }
    
    /* Update */
    new -> data = data;
    new -> next = NULL;
    new -> prev = *tail;
    
    /* For empty list */
    if(*head == NULL)
    {
        *head = new;
        *tail = new;
        return SUCCESS;
    }
    
    (*tail) -> next = new;
    *tail = new;
    
    return SUCCESS;
    
}

int dl_delete_list(Dlist **head, Dlist **tail)
{
    if(*head == NULL)
    {
        printf("List is empty\n");
        return FAILURE;
    }
    
    Dlist *temp = *head;
    Dlist *next_node = NULL;
    
    /* Traverse and free each node */
    while(temp != NULL)
    {
        next_node = temp -> next;
        free(temp);
        temp = next_node;
    }
    
    *head = NULL;
    *tail = NULL;
    
    return SUCCESS;
}