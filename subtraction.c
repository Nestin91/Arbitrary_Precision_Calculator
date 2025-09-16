/*
Name : Nestin Gregorios Sunny

Date : 06.09.2025

Description : 
	Arbitrary Precision Calculator

Sample Input :
	./a.out 248 - 109

Sample Output :
	139
*/

#include "apc.h"

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
	Dlist *temp1 = *tail1;
	Dlist *temp2 = *tail2;
	int borrow = 0;

	while (temp1 != NULL || temp2 != NULL)
	{
		int digit_1 = (temp1 != NULL) ? temp1 -> data : 0;
		int digit_2 = (temp2 != NULL) ? temp2 -> data : 0;
		
		digit_1 = digit_1 - borrow;
		if (digit_1 < digit_2)
		{
			digit_1 = digit_1 + 10;
			borrow = 1;
		}
		else
		{
			borrow = 0;
		}
		
		int subtract = digit_1 - digit_2;

		// Insert first
		if (dl_insert_first (headR, tailR, subtract) == FAILURE)
		{
			fprintf(stderr, "ERROR: Memory allocation failed during subtraction\n");
			return FAILURE;
		}
		
		// Move both pointers to previous node
		temp1 = (temp1 != NULL) ? temp1 -> prev : NULL;
		temp2 = (temp2 != NULL) ? temp2 -> prev : NULL;
	}
	
	// Remove leading zeros
	while (*headR && (*headR) -> data == 0 && (*headR) -> next != NULL)
	{
		Dlist *temp = *headR;
		*headR = (*headR) -> next;
		(*headR) -> prev = NULL;
		free(temp);
	}
	
	return SUCCESS;
}
