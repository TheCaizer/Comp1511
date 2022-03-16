//Jackie Cai
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET 26

int encrypt (int c, char mapping[],char array[]);

int main(void){
    char map[ALPHABET];
    int cha = 0;
    int i = 0;
    char array[26] = {'a','b','c', 'd' ,'e' , 'f' ,'g','h','i','j','k','l',
    'm','n' ,'o' , 'p' ,'q' , 'r', 's' ,'t' , 'u' , 'v' , 'w' ,'x' , 'y' , 'z'};

    while (i < ALPHABET) {
        map[i] = getchar();
        i++;
    }
    getchar();
    cha = getchar();
    while(cha != EOF){
        cha = encrypt(cha,map,array);
        printf("%c",cha);
        cha = getchar();
    }
    return 0;
}

int encrypt(int c, char mapping[],char array[]) {
    if (c >= 'A' && c <= 'Z') {
        c = tolower(c);
        int j = 0;
        int index;
        while(j < 26){
            if(mapping[j] == c){
                index = j;
                c = array[index];
                j = 26;
            }
            else{
                j++;
            }
        }
        c = toupper(c);
        return c;
    } 
    else if (c >= 'a' && c <= 'z') {
        int j = 0;
        int index;
        while(j < 26){
            if(mapping[j] == c){
                index = j;
                c = array[index];
                j = 26;
            }
            else{
                j++;
            }
        }
        return c;
    } else {
        return c;
    }
}

