#include<stdio.h>

#define SIZE 94
int main(void){
    int number = 32;
    int i = 0;
    while (i <= SIZE){
        printf("%3d 0x%x %c\n", number , number , number);
        i++;
        number++;
    }
}
