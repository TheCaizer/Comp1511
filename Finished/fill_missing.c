#include <stdio.h>
#define MAX_LENGTH 10000

int main(void){
    int array[MAX_LENGTH];
    int i = 0;
    int lar = 1;
    int smal = 1;
    int j = 0;
    int n = 0;
    int count = 0;
    while(scanf("%d" ,&array[i]) == 1){
        if (array[i] > lar){
            lar = array[i];
        }
        if (array[i] < smal){
            smal = array[i];
        }
        i++;
        n++;
    }
    int store[MAX_LENGTH];
    while(smal < lar){
//should check smal plus one if those numbers are in the array and continue checking until lar
        i = 0;
        while(i < n){
            if (smal == array[i]){
                i = n;
//ends the while loop
            }
            else if (smal != array[i]){
                i++;
                if(i == n){
                    store[j] = smal;
                    j++;
                    count++;
                }
            }
            
        }
        smal++;
    }
    j = 0;
    while(j < count - 1){
        printf("%d " ,store[j]);
        j++;
    }
    printf("%d\n",store[j]);  
}
