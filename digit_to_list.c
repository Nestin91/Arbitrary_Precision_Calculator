#include "apc.h"

/*store the operands into the list */
int digit_to_list(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *argv[])
{
    int i = 0, j = 0;

    // 1st operand
    while (argv[1][i])
    {
        /* 1.Create, 2.Validate, 3.Update*/
        Dlist *new = malloc(sizeof(Dlist));
        if (new == NULL)
        {
            fprintf(stderr, "ERROR: Memory allocation failed for first operand\n");
            return FAILURE;
        }
        if (argv[1][i] == '-')
        {
            i = 1;
        }
        
        new -> data = argv[1][i] - '0';
        new -> next = NULL;
        new -> prev = *tail1;

        // 1st node
        if (*head1 == NULL)
        {
            *tail1 = new;
            *head1 = new;
        }
        else
        {
            // Linking new node with old node
            (*tail1) -> next = new;
            *tail1 = new;
        }
        i++;
    }
    
    // 2nd Operand
    while (argv[3][j])
    {
        /* 1.Create, 2.Validate, 3.Update*/
        Dlist *new = malloc(sizeof(Dlist));
        if (new == NULL)
        {
            fprintf(stderr, "ERROR: Memory allocation failed for second operand\n");
            return FAILURE;
        }

        if (argv[3][j] == '-')
        {
            j = 1;
        }
        
        new -> data = argv[3][j] - '0';
        new -> next = NULL;
        new -> prev = *tail2;

        // 1st node
        if (*head2 == NULL)
        {
            *tail2 = new;
            *head2 = new;
        }
        else
        {
            // Linking new node with old node
            (*tail2) -> next = new;
            *tail2 = new;
        }
        j++;
    }
    
    return SUCCESS;  
}