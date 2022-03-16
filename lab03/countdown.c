//Jackie Cai countdown program
//z5259449 1/10/2019

#include<stdio.h>
#include<stdlib.h>
int main(void){
//initialise counter to 1
int counter = 10;

while (counter >= 0) {
    // print counter
    printf("%d\n", counter);
    // increment counter
    counter = counter - 1;
}
}
