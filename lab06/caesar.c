//Jackie Cai

#include<stdio.h>
#include<ctype.h>

int main(void){
    int caesar;
    scanf("%d" ,&caesar);
    //skip the \n
    getchar();
    int ch = getchar();
    while(ch != EOF){
        if(caesar < 0){
            caesar = 26 + (caesar % 26); 
        }
        else if (caesar > 26){
            caesar = caesar % 26;
        }
        if(ch >= 'A' && ch <= 'Z'){
            if(ch + caesar >= 91){
                ch = ch - 26;
            }
            ch = ch + caesar;
            printf("%c",ch);
        }
        else if(ch >= 'a' && ch <= 'z'){
            if(ch + caesar >= 123){
                ch = ch - 26;
            }
            ch = ch + caesar;
            printf("%c",ch);
        }
        else{
            printf("%c",ch);
        }
        ch = getchar();
    }
}
