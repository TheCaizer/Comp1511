//Jackie Cai percentage program
//z5259449 1/10/2019

#include<stdio.h>
#include<stdlib.h>

int main(void) {
    double total;
    double mark;
    double percentage;
    printf("Enter the total number of marks in the exam: ");
    scanf("%lf",&total);
    printf("Enter the number of marks the student was awarded: ");
    scanf("%lf",&mark);
percentage = mark * 100 / total;
printf("The student scored %.0lf%% in this exam.\n",percentage);
return 0;
}
