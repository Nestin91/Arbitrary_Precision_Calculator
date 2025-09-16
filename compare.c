#include "apc.h"

int compare(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2)
{
    /* Checking whether any of nodes are empty */
    if (*head1 == NULL)
    {
        return FAILURE;
    }
    if (*head2 == NULL)
    {
        return FAILURE;
    }

    int count1 = 0, count2 = 0;
    Dlist *temp1 = *head1, *temp2 = *head2;

    /* Traverse Both Nodes */
    while (temp1 != NULL)
    {
        count1++;
        temp1 = temp1 -> next;
    }
    while (temp2 != NULL)
    {
        count2++;
        temp2 = temp2 -> next;
    }

    int List1_len = count1;
    int List2_len = count2;

    if (List1_len > List2_len)
    {
        return 1;
    }
    else if (List1_len < List2_len)
    {
        return -1;
    }
    
    // Lengths are equal, compare digit by digit from head
    temp1 = *head1;
    temp2 = *head2;

    while(temp1 != NULL && temp2 != NULL)
    {
        if (temp1 -> data > temp2 -> data)
        {
            return 1;
        }
        else if(temp1 -> data < temp2 -> data)
        {
            return -1;
        }
        
        
        // Move both pointers to next node
        temp1 = temp1 -> next;
        temp2 = temp2 -> next;
    }

    return SUCCESS; // Equal
}