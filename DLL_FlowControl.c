/*Q3: Develop a simple data link layer that performs the flow control using 
the sliding window protocol, and loss recovery using the Go-Back-N mechanism.*/

#include <stdio.h>

int main(){
    int totalFrames, windowSize, i = 1, ack;

    printf("Enter the total number of frames: ");
    scanf("%d", &totalFrames);

    printf("Enter the window size: ");
    scanf("%d", &windowSize);

    while(i <= totalFrames){
        printf("\nSending frames: ");
        for(int j = 0; j < windowSize && (i + j) <= totalFrames; j++){
            printf("%d ", i + j);
        }
        printf("\n");

        printf("Enter last acknowledged frame (0 if none): ");
        scanf("%d", &ack);

        if(ack < i){
            printf("Timeout/Loss detected! Go-Back-N: retransmitting window starting from Frame %d\n", i);
        }else{
            printf("Frames up to %d acknowledged. Sliding window forward.\n", ack);
            i = ack + 1;
        }
    }

    printf("\nAll %d frames transmitted and acknowledged successfully.\n", totalFrames);
    return 0;
}

/*
O/P: 
Enter the total number of frames: 8
Enter the window size: 4

Sending frames: 1 2 3 4 
Enter last acknowledged frame (0 if none): 2
Frames up to 2 acknowledged. Sliding window forward.

Sending frames: 3 4 5 6 
Enter last acknowledged frame (0 if none): 6
Frames up to 6 acknowledged. Sliding window forward.

Sending frames: 7 8 
Enter last acknowledged frame (0 if none): 8
Frames up to 8 acknowledged. Sliding window forward.

All 8 frames transmitted and acknowledged successfully.
*/