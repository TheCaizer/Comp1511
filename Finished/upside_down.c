// Jackie Cai z5259449
// new2

#include<stdio.h>

int main(void){
    double numberA;
    double numberB;
    double numberC;
    printf("Please enter three numbers: ");
    scanf("%lf %lf %lf",&numberA ,&numberB ,&numberC);
    if(numberA > numberB && numberB > numberC){
        printf("down\n");
        return 0;
    }
    else if(numberC > numberB && numberB > numberA){
        printf("up\n");
        return 0;
    }
    else {
        printf("neither\n");
        return 0;
    }
}
