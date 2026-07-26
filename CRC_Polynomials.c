/*Q2: write a program to compute CRC code for the polynomials
CRC-12, CRC-16 and CRC CCIP */

/*
Generator polynomials used (standard bit patterns):
  CRC-12: x^12+x^11+x^3+x^2+x+1 -> 1100000001111  (13 bits)
  CRC-16: x^16+x^15+x^2+1 -> 11000000000000101 (17 bits)
  CRC-CCITT: x^16+x^12+x^5+1 -> 10001000000100001 (17 bits)
 
Method: plain binary (mod-2) division using XOR*/

#include <stdio.h>
#include <string.h>

#define MAX 200

/* Performs mod-2 (XOR) division of 'data' by 'gen'.
   data : data bits + appended zeros (dividend)
   gen  : generator polynomial bit string (divisor)
   Returns the remainder (CRC) as a string in 'remainder'.*/
void computeCRC(char *data, char *gen, char *remainder){
    int dataLen = strlen(data);
    int genLen  = strlen(gen);
    char temp[MAX];

    strcpy(temp, data);
    for(int i = 0; i <= dataLen - genLen; i++){
        if(temp[i] == '1'){ // divide only if leading bit is 1
            for(int j = 0; j < genLen; j++)
                temp[i + j] = (temp[i + j] == gen[j]) ? '0' : '1';   // XOR 
        }
    }
    // remainder = last (genLen - 1) bits of temp 
    strcpy(remainder, temp + (dataLen - (genLen - 1)));
}

// Appends (genLen-1) zeros to data and computes CRC, then prints result 
void runCRC(char *name, char *data, char *gen){
    char augmented[MAX], remainder[MAX], codeword[MAX];
    int genLen = strlen(gen);

    strcpy(augmented, data);
    for(int i = 0; i < genLen - 1; i++)
        strcat(augmented, "0");

    computeCRC(augmented, gen, remainder);
    strcpy(codeword, data);
    strcat(codeword, remainder);

    printf("\n----- %s -----\n", name);
    printf("Generator polynomial bits: %s\n", gen);
    printf("CRC (remainder): %s\n", remainder);
    printf("Transmitted codeword: %s\n", codeword);
}

int main(){
    char data[MAX];

    // Standard generator polynomials as bit strings 
    char crc12[] = "1100000001111";        // 13 bits -> 12-bit CRC  
    char crc16[] = "11000000000000101";    // 17 bits -> 16-bit CRC  
    char crcCCITT[] = "10001000000100001";    // 17 bits -> 16-bit CRC  

    printf("Enter data as a binary string (0s and 1s): ");
    scanf("%s", data);

    // validate input contains only 0s and 1s
    for(int i = 0; data[i] != '\0'; i++){
        if(data[i] != '0' && data[i] != '1'){
            printf("Invalid input! Please enter only 0s and 1s.\n");
            return 1;
        }
    }
    runCRC("CRC-12", data, crc12);
    runCRC("CRC-16", data, crc16);
    runCRC("CRC-CCITT", data, crcCCITT);
    return 0;
}

/*
O/P:
Enter data as a binary string (0s and 1s): 101001

----- CRC-12 -----
Generator polynomial bits: 1100000001111
CRC (remainder): 100100011111
Transmitted codeword: 101001100100011111

----- CRC-16 -----
Generator polynomial bits: 11000000000000101
CRC (remainder): 1000000011110101
Transmitted codeword: 1010011000000011110101

----- CRC-CCITT -----
Generator polynomial bits: 10001000000100001
CRC (remainder): 1011010101001011
Transmitted codeword: 1010011011010101001011
*/