#include<stdio.h>

int main(void){
    int word = getchar();
    while(word != EOF){
        printf("%c",word);
        word = getchar();
    }
}
