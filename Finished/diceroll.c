/* This is a program for comp1511 lecture two dice roll
Jackie Cai 
*/
#include <stdio.h>
int main(void){
    printf ("Type in the first result: ");
    int resultOne;
    scanf ("%d", &resultOne);
    printf ("Type in the second result: ");
    int resultTwo;
    scanf ("%d", &resultTwo);
    printf ("You rolled %d and %d \n", resultOne, resultTwo);
    int total;
    total = resultOne + resultTwo;
    printf ("The total is %d \n", total);
    int secret;
    secret = 7;
    if (total > secret) {
    printf ("You won \n");
    } else {
    printf("You lost");
    }
    return 0;    
}
