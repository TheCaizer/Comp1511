//Addition lab z5259449
//Jackie Cai 24 September 2019
#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int year;
    printf("Enter year:");
    scanf("%d", &year);
    if (year % 4 != 0) {
    printf("%d is not a leap year.\n",year);
}
    else if (year % 100 != 0) {
    printf("%d is a leap year.\n",year);
}   
    else if (year % 400 != 0) {
    printf("%d is not a leap year.\n",year);
}   
    else {
    printf("%d is a leap year.\n",year);
}
    return 0;
}
