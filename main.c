/*
Name : Nestin Gregorios Sunny

Date : 06.09.2025

Description : 
	Arbitrary Precision Calculator

Sample Input :
	./a.out

Sample Output :
	Arbitary Precision Caclculator
	******************************
	Syntax :
	./a.out <operand1> <operator> <operand2>

	Operations available:
        	1. Addition             (+)
        	2. Subtraction          (-)
        	3. Multiplication       (x)
        	4. Division             (/)

	ERROR: Read and Validate failed
*/

#include "apc.h"

int main(int argc, char **argv)
{
	/* Declare the pointers */
	Dlist *head1 = NULL, *tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL; 
    Dlist *headR = NULL, *tailR = NULL;

	/* Read and validate arguments */
	if(read_and_validate_args(argc, argv) != SUCCESS)
	{
		fprintf(stderr, "ERROR: Read and Validate failed\n");
		return FAILURE;
	}
	
	/* Extract signs and normalize input strings */
    int sign1 = 1, sign2 = 1;

	if (argv[1][0] == '-')
    {
        sign1 = -1;
        argv[1]++; // Skip '-' for digit conversion
    }

    if (argv[3][0] == '-')
    {
        sign2 = -1;
        argv[3]++;
    }

	
	/* Normalize operator to lowercase */
	char operator = tolower(argv[2][0]);

	/* Convert input strings to digit lists */
	if (digit_to_list(&head1,&tail1,&head2,&tail2,argv) != SUCCESS)
	{
		fprintf(stderr, "ERROR: Failed to convert digits to list\n");
		return FAILURE;
	}
		
	/* Perform operation based on operator */
	switch (operator)
	{
		case '+':
				/* call the function to perform the addition operation */
                if (sign1 == sign2)
            	{
                	if (addition(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS)
                	{
                    	if (sign1 == -1) printf("-");
                    	print_list(headR);
                	}
            	}
            	else
            	{
                	int cmp = compare(&head1, &tail1, &head2, &tail2);
                	if (cmp >= 0)
                	{
                    	if (subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS)
                    	{
                        	if (sign1 == -1) printf("-");
                        	print_list(headR);
                    	}
                	}
                	else
                	{
                    	if (subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR) == SUCCESS)
                    	{
                        	if (sign2 == -1) printf("-");
                        	print_list(headR);
                    	}
                	}
            	}
            break;

		case '-':	
				/* call the function to perform the subtraction operation */
				sign2 *= -1; // Flip sign of second operand
            	if (sign1 == sign2)
            	{
                	if (addition(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS)
                	{
                    	if (sign1 == -1) printf("-");
                    	print_list(headR);
                	}
            	}
            	else
            	{
                	int cmp = compare(&head1, &tail1, &head2, &tail2);
                	if (cmp >= 0)
                	{
                    	if (subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS)
                    	{
                        	if (sign1 == -1) printf("-");
                        	print_list(headR);
                    	}
                	}
                	else
                	{
                    	if (subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR) == SUCCESS)
                    	{
                        	if (sign2 == -1) printf("-");
                        	print_list(headR);
                    	}
                	}
            	}
            	break;

		case 'x':	
				/* call the function to perform the multiplication operation */
				{	
					int result_sign = (sign1 == sign2) ? 1 : -1;
            		if (multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS)
            		{
                		if (result_sign == -1) printf("-");
                		print_list(headR);
            		}
            		else
            		{
                		fprintf(stderr, "ERROR: Multiplication failed\n");
            		}
         			break;
				}

		case '/':	
				/* call the function to perform the division operation */
				{
					int result_sign = (sign1 == sign2) ? 1 : -1;
            		if (division(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS)
            		{
                		if (result_sign == -1) printf("-");
                		print_list(headR);
            		}
            		else
            		{
                		fprintf(stderr, "ERROR: Division failed\n");
            		}
            		break;
				}

		default:
				printf("Invalid Input:-( Try again...\n");
	}
	
	/* Clean up memory */
	dl_delete_list(&head1, &tail1);
	dl_delete_list(&head2, &tail2);
	dl_delete_list(&headR, &tailR);
	
	return SUCCESS;
}
