//Jackie Cai z5259449
//reverseArray.c 8/10/2019
#include <stdio.h>
#include<stdlib.h>
#define MAX_ARRAY 100

int main(void){
    int num[MAX_ARRAY] = {0};
    int i = 0;
    int result = 1;
    printf("Enter numbers forwards:\n");
    
    while(i <= MAX_ARRAY && result == 1){    
        result = scanf("%d",&num[i]);
        i++;
    }
    i = i - 2;
    printf("Reversed:\n");
    while(i >= 0){
        printf("%d \n",num[i]);
        i = i - 1;
    }
    return 0;   
}
