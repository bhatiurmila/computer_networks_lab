//Q8:Write a program for congestion control using Leaky bucket algorithm.

#include <stdio.h>

int main()
{
    int bucketSize, outputRate, packets, i;
    int bucket = 0, input;

    printf("Enter bucket size: ");
    scanf("%d", &bucketSize);

    printf("Enter output rate: ");
    scanf("%d", &outputRate);

    printf("Enter number of packets: ");
    scanf("%d", &packets);

    for(i = 1; i <= packets; i++)
    {
        printf("\nEnter packet size %d: ", i);
        scanf("%d", &input);

        if(bucket + input <= bucketSize)
        {
            bucket += input;
        }
        else
        {
            printf("Packet dropped (Bucket Overflow)\n");
        }

        printf("Bucket Content before leak = %d\n", bucket);

        if(bucket >= outputRate)
            bucket -= outputRate;
        else
            bucket = 0;

        printf("Bucket Content after leak = %d\n", bucket);
    }

    return 0;
}

/*
O/P:
Enter bucket size: 10
Enter output rate: 4
Enter number of packets: 5

Enter packet size 1: 5
Bucket Content before leak = 5
Bucket Content after leak = 1

Enter packet size 2: 3
Bucket Content before leak = 4
Bucket Content after leak = 0

Enter packet size 3: 6
Bucket Content before leak = 6
Bucket Content after leak = 2

Enter packet size 4: 2
Bucket Content before leak = 4
Bucket Content after leak = 0

Enter packet size 5: 4
Bucket Content before leak = 4
Bucket Content after leak = 0
*/