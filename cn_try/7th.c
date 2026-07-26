//Q7:Implement data encryption and data decryption 

#include <stdio.h>
#include <string.h>

int main()
{
    char text[100];
    int key, i;

    printf("Enter the text: ");
    scanf("%s", text);

    printf("Enter the key: ");
    scanf("%d", &key);

    // Encryption
    for(i = 0; text[i] != '\0'; i++)
    {
        text[i] = text[i] + key;
    }

    printf("\nEncrypted Text: %s", text);

    // Decryption
    for(i = 0; text[i] != '\0'; i++)
    {
        text[i] = text[i] - key;
    }

    printf("\nDecrypted Text: %s\n", text);

    return 0;
}

/*
O/P:
Enter the text: hello
Enter the key: 2

Encrypted Text: jgnnq
Decrypted Text: hello*/