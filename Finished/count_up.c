#include <stdio.h>

int main(void){
    int lower;
    int upper;
    printf("Enter lower: ");
    scanf("%d",&lower);
    printf("Enter upper: ");
    scanf("%d",&upper);
    lower = lower + 1;
    while(lower < upper){
        printf("%d \n",lower);
        lower++;
    }
}
