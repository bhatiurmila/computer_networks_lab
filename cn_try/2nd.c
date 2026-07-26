//Q2:Write a program to compute CRC code for the polynomials 
//CRC-12, CRC-16 and CRC CCIP 

#include <stdio.h>
#include <string.h>

void computeCRC(char data[], char divisor[])
{
    char dividend[100], temp[100];
    int dataLen, divLen, i, j;

    strcpy(dividend, data);

    dataLen = strlen(data);
    divLen = strlen(divisor);

    /* Append zeros */
    for(i = 0; i < divLen - 1; i++)
        dividend[dataLen + i] = '0';

    dividend[dataLen + divLen - 1] = '\0';

    strcpy(temp, dividend);

    /* Modulo-2 division */
    for(i = 0; i <= strlen(temp) - divLen; i++)
    {
        if(temp[i] == '1')
        {
            for(j = 0; j < divLen; j++)
            {
                temp[i + j] =
                    (temp[i + j] == divisor[j]) ? '0' : '1';
            }
        }
    }

    printf("\nDataword      : %s", data);
    printf("\nGenerator     : %s", divisor);

    printf("\nCRC Remainder : ");
    for(i = strlen(temp) - (divLen - 1); i < strlen(temp); i++)
        printf("%c", temp[i]);

    printf("\nCodeword      : %s", data);

    for(i = strlen(temp) - (divLen - 1); i < strlen(temp); i++)
        printf("%c", temp[i]);

    printf("\n");
}

int main()
{
    char data[100];
    int choice;

    printf("Enter binary data: ");
    scanf("%s", data);

    printf("\nChoose CRC Polynomial");
    printf("\n1. CRC-12");
    printf("\n2. CRC-16");
    printf("\n3. CRC-CCITT");
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            computeCRC(data, "1100000001111");
            break;

        case 2:
            computeCRC(data, "11000000000000101");
            break;

        case 3:
            computeCRC(data, "10001000000100001");
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}

/*
O/P:
Enter binary data: 01001100

Choose CRC Polynomial
1. CRC-12
2. CRC-16
3. CRC-CCITT
Enter choice: 3

Dataword      : 01001100
Generator     : 10001000000100001
CRC Remainder : 1000100101001000
Codeword      : 010011001000100101001000

Choose CRC Polynomial
1. CRC-12
2. CRC-16
3. CRC-CCITT
Enter choice: Invalid choice!
*/