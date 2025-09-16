#include "apc.h"

void print_list(Dlist *head)
{
    while (head)
    {
        printf("%d", head -> data);
        head = head -> next;
    }
    printf("\n");
}