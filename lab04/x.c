//Jackie Cai z5259449
//x.c 8/10/2019

#include <stdio.h>
#include<stdlib.h>

int main(void){
    int size;
    int x = 0;
    int y = 0;
    
    printf("Enter size: ");
    scanf("%d",&size);
    while(x<size){
        y=0;
        while(y<size){
        if(y == x || x == size-1-y)
        {
            printf("*");
        }
        else
        {
            printf("-");
        }
        y++;
    }
    printf("\n");
    x++;
}
}
