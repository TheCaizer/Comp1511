#include <stdio.h>
#include <stdlib.h>

int main(void){
    int num;
    int i = 0;
    int total = 0;
    int num1;
    printf("How many numbers: ");
    scanf("%d",&num);
    while(i < num){
        scanf("%d",&num1);
        total = num1 + total;
        i++;
    }
    printf("The sum is: %d\n",total);
    return 0;
}
