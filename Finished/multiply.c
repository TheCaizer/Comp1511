// Jackie Cai z5259449
// 8/10/19 multiply

#include<stdio.h>
int main(void){
    int numberA;
    int numberB;
    int result;
//Assign two variable to get and then result to print
    scanf("%d %d",&numberA ,&numberB);
    result = numberA * numberB;
    if(result < 0){
        result = result * -1;
//If the number is negative it times it by negative to get a positive
        printf("%d\n",result);
        return 0;
    }
    else if (result == 0){
        printf("zero\n");
//If it is zero it prints the zero could also say in A B is zero print zero
        return 0;
    }
    else {
        printf("%d\n",result);
//print all positive numbers since
    }
}
