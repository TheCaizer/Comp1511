#include<stdio.h>
#include<string.h>

#define MAX 256

int main(void){
    char line[MAX];
    int n;

    fgets(line,MAX,stdin);
    scanf("%d",&n);
    printf("The character in position %d is '%c'\n",n ,line[n]);
    return 0;
}
