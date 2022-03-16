// Easter program finder
//Jackie Cai z5259449 25 Sep 2019
#include<stdio.h>
#include<stdlib.h>

int main(void) {
    printf("Enter year: ");
    int year;
    scanf("%d",&year);
    int a=year%19;
    int b=year/100;
    int c=year%100;
    int d=b/4;
    int e=b%4;
    int f=(b+8)/25;
    int g=(b-f+1)/3;
    int h=(19*a+b-d-g+15)%30;
    int i=c/4;
    int k=c%4;
    int l=(32+2*e+2*i-h-k)%7;
    int m=(a+11*h+22*l)/451;
    int EasterMonth =(h+l-7*m+114)/31;
    int p=(h+l-7*m+114)%31;
    int EasterDate=p+1 ;
    if (EasterMonth == 1) {
        printf("Easter is Janurary %d in %d.\n", EasterDate, year); 
        return 0;
    }
    else if (EasterMonth == 2){
    printf("Easter is Feburary %d in %d.\n", EasterDate, year); 
    return 0;
    }
    else if (EasterMonth == 3){
    printf("Easter is March %d in %d.\n", EasterDate, year); 
    return 0;
    }
    else if (EasterMonth == 4){
    printf("Easter is April %d in %d.\n", EasterDate, year); 
    return 0;
    }
    else if (EasterMonth == 5){
    printf("Easter is May %d in %d.\n", EasterDate, year); 
    return 0;
    }
    else if (EasterMonth == 6){
    printf("Easter is June %d in %d.\n", EasterDate, year); 
    return 0;
}
    else if (EasterMonth == 7){
    printf("Easter is July %d in %d.\n", EasterDate, year); 
    return 0;    
    }
    else if (EasterMonth == 8){
    printf("Easter is August %d in %d.\n", EasterDate, year); 
        return 0;
    }
    else if (EasterMonth == 9){
    printf("Easter is  September %d in %d.\n", EasterDate, year); 
    return 0;
    }
    else if (EasterMonth == 10){
    printf("Easter is October %d in %d.\n", EasterDate, year); 
    return 0;    
    }
    else if (EasterMonth == 11){
    printf("Easter is November %d in %d.\n", EasterDate, year); 
    return 0;    
    }
    else if (EasterMonth == 12){
    printf("Easter is December %d in %d.\n", EasterDate, year); 
    return 0;    
    }
    else {
    printf("You have entered an invalid month");
    return 0;
    }
    
return 0;
}
