// COMP1511 Week 5 Lab: Vector Permutation
//
// This program was written by Jackie Cai (z5259449)
// on 15/10/19

#include <stdio.h>
#include <math.h>

int main(void){
    int vLength;
    int i = 0;
    
    printf("Enter vector length: ");
    scanf("%d",&vLength);
    int vector[vLength];
    printf("Enter vector: ");
    while(i < vLength){
        scanf("%d",&vector[i]);
        i++;
    }
    printf("Enter permutation: ");
    i = 0;
    int permutation[vLength];
    while(i < vLength){
        scanf("%d",&permutation[i]);
        if(permutation[i] >= vLength){
        printf("Invalid permutation\n");
        return 0;
        }
        i++;
        
    }
    
    int j = 0;
    while(j < vLength){
        if(j < vLength - 1){
        printf("%d ",vector[permutation[j]]);
        j++;
        }
        else if(j == vLength - 1){
        printf("%d\n",vector[permutation[j]]);
        j++;
        }
    }
}
    

