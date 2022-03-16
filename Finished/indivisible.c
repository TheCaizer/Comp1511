#include <stdio.h>

#define MAX 1000

void  divisble(int length, int array[]);

int main(void) {
    int numbers[MAX];

    int n = 0;
    while (n < MAX && scanf("%d", &numbers[n]) == 1) {
        n++;
    }

    printf("Indivisible numbers:");
    divisble(n, numbers);

    return 0;
}

void divisble(int length, int array[]) {
    int i = 0;
    while (i < length) {
        int factors = 0;
        int j = 0;
        while (j < length) {
            if (array[i] % array[j] == 0) {
                factors++;
            }
            j++;
        }
        if (factors == 1) {
            printf(" %d", array[i]);
        }
        i++;
    }
    printf("\n");
}
