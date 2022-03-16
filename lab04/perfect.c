//Jackie Cai z5259449
//perfect.c 8/10/2019

#include <stdio.h>
#include<stdlib.h>

int main(void) {
    int num;
    int counter = 1;
    int counterTotal = 0;
    printf("Enter number: ");
    scanf("%d" ,&num);
    printf("The factors of %d are:\n" ,num);
    while(num >= counter){
        if(num % counter == 0){
            printf("%d \n",counter);
            counterTotal = counterTotal + counter;
        }
        counter++;
    }
    printf("Sum of factors = %d \n", counterTotal);
    if(num == counterTotal/2){
    printf("%d is a perfect number\n",num);
    }
    else{
    printf("%d is not a perfect number\n",num);    
    }
    return 0;
}
