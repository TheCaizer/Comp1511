#include <stdio.h>
#include <stdlib.h>
int main(void){
    int i;
    int j;
    int rows;
    printf("Enter size: ");
    scanf("%d",&rows);
    i=1;
    while(i<=rows){
        j=1;
        while(j<=i){
            printf(" ");
        if(j==1 || j==i ||i==rows ){
            printf("*");//print star
        }
        else{
            printf(" "); //print inside space
        }
        j++;
        }
    i++;
    printf("\n");//Move to the next line for print
    }
    return 0;
}

