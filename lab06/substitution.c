//Jackie Cai
#include <stdio.h>
#include <string.h>

#define ALPHABET 26

int encrypt (int c, char mapping[]);

int main(void){
    char map[ALPHABET];
    int cha = 0;
    int i = 0;

    while (i < ALPHABET) {
        map[i] = getchar();
        i++;
    }
    getchar();
    cha = getchar();
    while(cha != EOF){
        cha = encrypt(cha,map);
        printf("%c",cha);
        cha = getchar();
    }
    return 0;
}

int encrypt(int c, char mapping[]) {
    if (c >= 'A' && c <= 'Z') {
    return mapping[c - 'A'] - 'a' + 'A';
    } else if (c >= 'a' && c <= 'z') {
        return mapping[c - 'a'];
    } else {
        return c;
    }
}

