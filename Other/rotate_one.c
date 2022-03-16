// Rotate a character by one -- i.e. turn 'a' to 'b', 'b' to 'c', ...
// 'z' to 'a'.
// Created by ... (z0000000)
// Created on 2019-??-??

#include <stdio.h>
#include <stdlib.h>

int rotateOne(int c);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(int argc, char *argv[]) {

    // Scan in the first character.
    int c = getchar();

    // Loop until there are no more characters to scan.
    while (c != EOF) {
        // Print the character, "rotated" once.
        putchar(rotateOne(c));

        // Get the next character.
        c = getchar();
    }

    return 0;
}
// END OF MAIN FUNCTION

// "Rotate" the letter by one, i.e. change 'a' to 'b', 'b' to 'c',
// 'z' to 'a'.
int rotateOne(int c) {
    if(c >= 97 && c <= 122){
        c = c + 1;
        if(c > 122){
            c = c - 26;
        }
        return c;
    }
    if(c >= 65 && c <= 90){
        c = c + 1;
        if(c > 90){
            c = c - 26;
        }
        return c;
    }
    else{
        return c;
    }
}
