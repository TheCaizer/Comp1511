#include<stdio.h>

int main(void){
    int num2;
    int num1;
    int num3;
    printf("Enter integer: ");
    scanf("%d",&num1);
    printf("Enter integer: ");
    scanf("%d",&num2);
    printf("Enter integer: ");
    scanf("%d",&num3);
    if (num1 <= num2 &&  num2 <= num3){
        printf("Middle: %d \n",num2);      
        return 0;
    }
    else if(num1 <= num3 && num3 <= num2){
        printf("Middle: %d \n",num3);
        return 0;
    }
    else if (num2 <= num1 &&  num1 <= num3){
        printf("Middle: %d \n",num1);      
        return 0;
    }
    else if(num2 <= num3 && num3 <= num1){
        printf("Middle: %d \n",num3);
        return 0;
    }
    else if (num3 <= num1 &&  num1 <= num2){
        printf("Middle: %d \n" ,num1);      
        return 0;
    }
    else if(num3 <= num2 && num2 <= num1){
        printf("Middle: %d\n" ,num2);
        return 0;
    }   
}
