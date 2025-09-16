#include "apc.h"

/* Validate Operand is only digits or not */
int validate_operand(char *str)
{
    int i = 0;

    // Empty string check
    if (str[0] == '\0')
    {
        return FAILURE;
    }
    if (str[0] == '-')
    {
        // Start checking from the next character
        i = 1;

        //Alone '-' is also not a valid number
        if (str[1] == '\0')
        {
            return FAILURE;
        }
    }
    
    // Check remaining characters are digits
    while (str[i])
    {
        if (!isdigit((unsigned char)str[i]))
        {
            return FAILURE;
        }
        i++;
    }
    return SUCCESS;
}

/* Read and validate args from argv */
int read_and_validate_args(int argc,char *argv[])
{
    /* Check argument count */
    if (argc == 1)
    {
        printf("Arbitary Precision Caclculator\n");
        printf("******************************\n");
        printf("Syntax :\n");
        printf("./a.out <operand1> <operator> <operand2>\n\n");
        printf("Operations available:\n");
        printf("\t1. Addition\t\t(+)\n");
        printf("\t2. Subtraction\t\t(-)\n");
        printf("\t3. Multiplication\t(x)\n");
        printf("\t4. Division\t\t(/)\n\n");
        return FAILURE;
    }
    
    if (argc != 4)
    {
        fprintf(stderr,"ERROR: Insufficient arguments provided\n");
        return FAILURE;
    }

    if (validate_operand (argv[1]) == FAILURE || validate_operand (argv[3]) == FAILURE)
    {
        fprintf(stderr, "ERROR: Operands should be only digits\n");
        return FAILURE;
    }
    
    if (strlen(argv[2]) != 1)
    {
        fprintf(stderr, "ERROR: Operator should be a single character (+, -, x, /)\n");
        return FAILURE;
    }
    
    return SUCCESS;
}