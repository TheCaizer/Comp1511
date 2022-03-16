#include <stdio.h>

// return the number of "bigger" values in an array (i.e. larger than 99
// or smaller than -99).
int count_bigger(int length, int array[]) {
    // PUT YOUR CODE HERE (you must change the next line!)
    int i = 0;
    //two variables set to zero to as a stopper and a counter
    int j = 0;
    int checker = 0;
    //variable checks the number 
    while (i < length){
        checker = array[i];
        if (checker > 99 || checker < -99){
        //checks if the number is greater or less than 99/-99
            j++;
        }
        i++;
    }
    return j;
}

// This is a simple main function which could be used
// to test your count_bigger function.
// It will not be marked.
// Only your count_bigger function will be marked.

#define TEST_ARRAY_SIZE 8

int main(void) {
    int test_array[TEST_ARRAY_SIZE] = {141, 5, 92, 6, 535, -89, -752, -3};

    int result = count_bigger(TEST_ARRAY_SIZE, test_array);

    printf("%d\n", result);
    return 0;
}
