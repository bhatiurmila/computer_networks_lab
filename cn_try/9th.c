//Q9:Write a program for frame sorting techniques used in buffers. 

#include <stdio.h>

int main()
{
    int frames[20], n, i, j, temp;

    printf("Enter the number of frames: ");
    scanf("%d", &n);

    printf("Enter the frame numbers:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &frames[i]);
    }

    // Bubble Sort
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(frames[j] > frames[j + 1])
            {
                temp = frames[j];
                frames[j] = frames[j + 1];
                frames[j + 1] = temp;
            }
        }
    }

    printf("\nFrames after sorting:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d ", frames[i]);
    }

    printf("\n");

    return 0;
}

/*
O/P:
Enter the number of frames: 6
Enter the frame numbers:
2 3 4 5 6 1

Frames after sorting:
1 2 3 4 5 6 
*/