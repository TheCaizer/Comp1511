// COMP1511 Week 5 Lab: Circle Facts
//
// This program was written by Jackie Cai (z5259449)
// on 15/10/19
//
// This program prints out facts about a circle given its radius,
// using functions.
//

#include <stdio.h>
#include <math.h>

int main(void){
    int vLength = 0;
    int i = 0;
    printf("Enter vector length: ");
    scanf("%d",&vLength);
    int vector1[vLength];
    int vector2[vLength];
    printf("Enter vector 1: ");
    while(i < vLength){
        scanf("%d",&vector1[i]);
        i++;
    }
    i = 0;
    printf("Enter vector 2: ");
    while(i < vLength){
        scanf("%d",&vector2[i]);
        i++;
    }
    double euclidean = 0;
    int j = 0;
    while(j < vLength){
        euclidean = ((vector1[j] - vector2[j]) * (vector1[j] - vector2[j])) + euclidean;
        j++;
    }
    euclidean = sqrt(euclidean);
    printf("Euclidean distance = %lf\n" ,euclidean);
}
