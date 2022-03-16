#include <stdio.h>

// Return the number of "small" values in an array.
// A "small" value is between -9 and 9 inclusive.
int count_small(int length, int array[]) {
    int i = 0;
    int count = 0;
    while(i < length){
        if(array[i] <= 9 && array[i] >= -9){
            count++;
        }
        i++;
    }
    return count;
}

// This is a simple main function which could be used
// to test your count_small function.
// It will not be marked.
// Only your count_small function will be marked.

#define TEST_ARRAY_SIZE 9

int main(void) {
    int test_array[TEST_ARRAY_SIZE] = {16, 7, 8, 12, 13, -9, -3, 12, -9};

    int result = count_small(TEST_ARRAY_SIZE, test_array);
    printf("%d\n", result);

    return 0;
}
