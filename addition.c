/*
Name : Nestin Gregorios Sunny

Date : 06.09.2025

Description : 
	Arbitrary Precision Calculator

Sample Input :
	./a.out -9876 + 5678

Sample Output :
	4198
*/

#include "apc.h"

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
	int carry = 0;
	Dlist *temp1 = *tail1; 
	Dlist *temp2 = *tail2;

	while (temp1 != NULL || temp2 != NULL || carry)
	{
		int sum = carry;
		if (temp1 != NULL)
		{
			sum += temp1 -> data;
			temp1 = temp1 -> prev;
		}
		
		if (temp2 != NULL)
		{
			sum += temp2 -> data;
			temp2 = temp2 -> prev;
		}
		
		int digit = sum % 10;
		carry = sum / 10;

		// insert_first
		if(dl_insert_first (headR, tailR, digit) == FAILURE)
		{
			fprintf(stderr, "ERROR: Memory allocation failed during addition\n");
			return FAILURE;
		}
	}
	
	return SUCCESS;
}
