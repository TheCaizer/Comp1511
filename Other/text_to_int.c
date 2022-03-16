#include<stdio.h>
#include<string.h>

int main(void){
    int word = getchar();
    while(word != EOF){
        printf("%d\n" , word);
        word = getchar();
    }
}
