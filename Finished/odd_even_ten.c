#include <stdio.h>

int main(void){
    int i = 0;
    int number[10] = {0};
    while(i < 10){
        scanf("%d",&number[i]);
        i = i + 1;
    }
    printf("Odd numbers were:");
    i = 0;
    while(i < 10){
        if(number[i]%2 == 1){
            printf(" %d",number[i]);
        }
        i++;
    }
    printf("\nEven numbers were:");
    i = 0;
    while(i < 10){
        if(number[i]%2 == 0){
            printf(" %d",number[i]);
        }
        i++;
    }
    printf("\n");
}
