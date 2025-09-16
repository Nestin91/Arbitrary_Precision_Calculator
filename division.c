/*
Name : Nestin Gregorios Sunny

Date : 06.09.2025

Description : 
	Arbitrary Precision Calculator

Sample Input :
	./a.out 127 / 2

Sample Output :
	-63
*/

#include "apc.h"

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
	
	// Division by zero
	if (*head2 == NULL || ((*head2) -> data == 0 && (*head2) -> next == NULL))
	{
		return FAILURE;
	}
	
	// Dividend < Divisor
	if (compare(head1, tail1, head2, tail2) < 0)
	{
		dl_insert_last(headR, tailR, 0);
		return SUCCESS;
	}
	
	int div = 0;
	Dlist *tempH = NULL, *tempT = NULL;

	while (compare(head1, tail1, head2, tail2) >= 0)
	{
		// Clear previous result
		//dl_delete_list(&tempH, &tempT);

		if (subtraction(head1, tail1, head2, tail2, &tempH, &tempT) == FAILURE)
		{
			return FAILURE;
		}
		
		//Delete list 1
		dl_delete_list(head1, tail1);

		//Update divident with result of subtraction
		*head1 = tempH;
		*tail1 = tempT;
		tempH = tempT = NULL;
		div++;
	}
	
	//printf("%d\n", div);
	char buffer[20];
	sprintf(buffer, "%d", div);
	for (int i = 0; buffer[i]; i++)
	{
		dl_insert_last(headR, tailR, buffer[i] - '0');
	}
	
	return SUCCESS;
}
