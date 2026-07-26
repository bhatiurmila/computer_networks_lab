/*Q1: Implement the data link layer framing methods such as 
character count framing, character-stuffing and bit stuffing.*/

#include <stdio.h>
#include <string.h>

// Character Count Framing 
void characterCount(){
    char data[100];
    printf("Enter data: ");
    scanf(" %[^\n]", data);
    int len = strlen(data);
    printf("\nFramed Output:\n %d%s\n", len + 1, data);
}

// Character Stuffing 
void characterStuffing(){
    char data[100];
    char DLE = '$';   // Data Link Escape character
    char STX = '*';   // Start of Text
    char ETX = '#';   // End of Text

    printf("Enter data: ");
    scanf(" %[^\n]", data);
    printf("\nFramed Output:\n %c%c", DLE, STX); // Start of frame

    for (int i = 0; data[i] != '\0'; i++){
        if(data[i] == DLE)
            printf("%c", DLE); // Stuff extra DLE if DLE occurs in data
        printf("%c", data[i]);
    }
    printf("%c%c\n", DLE, ETX); // End of frame
}

// Bit Stuffing 
void bitStuffing(){
    char bits[100];
    printf("Enter binary data (0s and 1s only): ");
    scanf(" %s", bits);
    int len = strlen(bits);
    printf("\nFramed Output (Bit Stuffing Method):\n");
    printf("01111110"); // Starting flag

    int count = 0;
    for(int i = 0; i < len; i++){
        printf("%c", bits[i]);
        if(bits[i] == '1'){
            count++;
            if(count == 5){
                printf("0"); 
                count = 0;
            }
        }else{
            count = 0;
        }
    }
    printf("01111110\n"); // Ending flag
}

int main(){
    int choice;
    do{
        printf("\n----- Data Link Layer Framing Methods -----\n");
        printf("1. Character Count Framing\n");
        printf("2. Character Stuffing\n");
        printf("3. Bit Stuffing\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                characterCount();
                break;
            case 2:
                characterStuffing();
                break;
            case 3:
                bitStuffing();
                break;
            case 4:
                printf("Exiting program....\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }while(choice != 4);
    return 0;
}

/*
O/P:
----- Data Link Layer Framing Methods -----
1. Character Count Framing
2. Character Stuffing
3. Bit Stuffing
4. Exit
Enter your choice: 1
Enter data: Hello world

Framed Output:
 12Hello world

----- Data Link Layer Framing Methods -----
1. Character Count Framing
2. Character Stuffing
3. Bit Stuffing
4. Exit
Enter your choice: 2
Enter data: Hello world$

Framed Output:
 $*Hello world$$$#

----- Data Link Layer Framing Methods -----
1. Character Count Framing
2. Character Stuffing
3. Bit Stuffing
4. Exit
Enter your choice: 3
Enter binary data (0s and 1s only): 101101

Framed Output (Bit Stuffing Method):
0111111010110101111110

----- Data Link Layer Framing Methods -----
1. Character Count Framing
2. Character Stuffing
3. Bit Stuffing
4. Exit
Enter your choice: 4
Exiting program...
*/