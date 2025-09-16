/*
Name : Nestin Gregorios Sunny

Date : 06.09.2025

Description : 
	Arbitrary Precision Calculator

Sample Input :
	./a.out 12 x 20

Sample Output :
	240
*/

#include "apc.h"

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
	/*
	if (*head1 == NULL || *head2 == NULL)
	{
		// Handle the case where either number is zero
		dl_insert_first(headR, tailR, 0);
		return SUCCESS;
	}*/
	
	Dlist *temp2 = *tail2;
	int i, count = 0;

	Dlist *headR2 = NULL;
	Dlist *tailR2 = NULL;

	// Initially assigning 0 to resultant
	if(dl_insert_first(&headR2, &tailR2, 0) == FAILURE)
	{
		return FAILURE;
	}

	while (temp2 != NULL)
	{
		Dlist *temp1 = *tail1;
		Dlist *headR1 = NULL;
		Dlist *tailR1 = NULL;
		int carry = 0;

		// Assign tail everytime
		if (*tail1 != NULL)
		{
			temp1 = *tail1;
		}
		
		/*
		if (temp2 -> data == 0)
		{
			count++;
			temp2 = temp2 -> prev;
			continue;
		}*/
		
		
		//Adding zeros to the empty list
		for (i = 0; i < count; i++)
		{
			if(dl_insert_first(&headR1, &tailR1, 0) == FAILURE)
			{
				dl_delete_list(&headR1, &tailR1);
				dl_delete_list(&headR2, &tailR2);
				return FAILURE;
			}
		}
		
		int digit = temp2 -> data;

		// Multiply each digit of head1 with current digit of head2
		while (temp1 != NULL)
		{
			/* Logic */
			int product = temp1 -> data * digit + carry;
			carry = product / 10;
			product = product % 10;
			if(dl_insert_first(&headR1, &tailR1, product) == FAILURE)
			{
				dl_delete_list(&headR1, &tailR1);
				dl_delete_list(&headR2, &tailR2);
				return FAILURE;
			}
			temp1 = temp1 -> prev;
		}
		
		if (carry > 0)
		{
			if(dl_insert_first(&headR1, &tailR1, carry) == FAILURE)
			{
				dl_delete_list(&headR1, &tailR1);
				dl_delete_list(&headR2, &tailR2);
				return FAILURE;
			}
		}
		
		// Add partial product to final result
		if(addition(&headR1, &tailR1, &headR2, &tailR2, headR, tailR) == FAILURE)
		{
			dl_delete_list(&headR1, &tailR1);
			dl_delete_list(&headR2, &tailR2);
			return FAILURE;
		}

		// Remove partial list
		dl_delete_list(&headR1, &tailR1);
		dl_delete_list(&headR2, &tailR2);

		// Updating resultant list 2
		headR2 = *headR;
		tailR2 = *tailR;

		// Making resultant list to NULL
		*headR = NULL;
		*tailR = NULL;

		temp2 = temp2 -> prev;
		count++;
	}

	*headR = headR2;
	*tailR = tailR2;
	
	// Remove headR2 and tailR2
	//dl_delete_list(&headR2, &tailR2);

	// Removing leading zeros
	while ((*headR) -> data == 0) 
	{
		Dlist *temp;
		if ((*headR) -> next != NULL)
		{
			temp = *headR;
			*headR = temp -> next;
			(*headR) -> prev = NULL;
		}
		else
		{
			break;
		}
		free(temp);
	}
	
	return SUCCESS;	
}
