//Q1:Implement the data link layer framing methods such as 
//character, character-stuffing and bit stuffing. 

#include <stdio.h> 
#include <string.h>
//1.Character Count 
void charCount(){
    char data[100];
    int len;
    printf("Enter data: ");
    scanf("%s", data);
    len=strlen(data);
    printf("Formed Data:%d%s\n",len,data);
}
//2.Character Stuffing
void charStuffing(){
    char data[100], stuffed[200];
    int i,j=0;
    printf("Enter data: ");
    scanf("%s", data);
    stuffed[j++]= 'S'; //start
    for(i=0; data[i]!='\0'; i++){
        if(data[i]=='E'){
            stuffed[j++]='E';
        }else{
            stuffed[j++]=data[i];
        }
    }
    stuffed[j++]= 'E'; //End
    stuffed[j]= '\0';
    printf("Stuffed Data: %s\n", stuffed);
}
//3. Bit Stuffing
void bitStuffing(){
    char data[100], stuffed[200];
    int i,j=0, count=0;
    printf("Enter Data: ");
    scanf("%s", data);
    for(i=0; data[i]!='\0'; i++){
        stuffed[j++]= data[i];
        if(data[i]=='1'){
            count++;
            if(count==5){
                stuffed[j++]='0';
                count=0;
            }
        }else{
            count=0;
        }
    }
    stuffed[j]='\0';
    printf("Stuffed Data: %s\n", stuffed);
}
int main(){
    int choice;
    while(1){
        printf("\n---Data link layer framing---\n");
        printf("1.Character Count\n");
        printf("2.Character Stuffing\n");
        printf("3.Bit Stuffing\n");
        printf("4.Exit...\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            charCount();
            break;
            case 2:
            charStuffing();
            break;
            case 3:
            bitStuffing();
            break;
            case 4:
            printf("Exitng...\n");
            return 0;
            default:
            printf("Invalid choice!\n");
        }
    }
}

/*
O/P:
---Data link layer framing---
1.Character Count
2.Character Stuffing
3.Bit Stuffing
4.Exit...
Enter your choice: 1
Enter data: World 
Formed Data:5World

---Data link layer framing---
1.Character Count
2.Character Stuffing
3.Bit Stuffing
4.Exit...
Enter your choice: 2
Enter data: Hello
Stuffed Data: SHelloE

---Data link layer framing---
1.Character Count
2.Character Stuffing
3.Bit Stuffing
4.Exit...
Enter your choice: 3
Enter Data: 1111111111
Stuffed Data: 111110111110

---Data link layer framing---
1.Character Count
2.Character Stuffing
3.Bit Stuffing
4.Exit...
Enter your choice: 4
Exitng...
*/