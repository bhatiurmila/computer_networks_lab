//Q3:Develop a simple data link layer that performs the flow control using the 
//sliding window protocol, and loss recovery using the Go-Back-N mechanism. 

#include <stdio.h>

int main()
{
    int totalFrames, windowSize, i = 1, ack;

    printf("Enter the total number of frames: ");
    scanf("%d", &totalFrames);

    printf("Enter the window size: ");
    scanf("%d", &windowSize);

    while (i <= totalFrames)
    {
        printf("\nSending frames: ");
        for (int j = 0; j < windowSize && (i + j) <= totalFrames; j++)
        {
            printf("%d ", i + j);
        }

        printf("\nEnter last acknowledged frame: ");
        scanf("%d", &ack);

        if (ack < i)
        {
            printf("Frame lost! Go-Back-N retransmits from Frame %d\n", i);
        }
        else
        {
            i = ack + 1;
        }
    }

    printf("\nAll frames transmitted successfully.\n");

    return 0;
}

/*
O/P:
Enter the total number of frames: 5
Enter the window size: 3

Sending frames: 1 2 3 
Enter last acknowledged frame: 2

Sending frames: 3 4 5 
Enter last acknowledged frame: 5

All frames transmitted successfully.
*/