//Addition lab z5259449
//Jackie Cai 24 September 2019
#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int NumberSide;
    int NumberRoll;
    double RangeHigher;

    printf("Enter the number of sides on your dice: ");
    scanf("%d",&NumberSide);
    printf("Enter the number of dice being rolled: ");
    scanf("%d",&NumberRoll);
    if (NumberSide <= 0 || NumberRoll <= 0) {
    printf("These dice will not produce a range. \n");
    return 0;}   
    RangeHigher = NumberRoll * NumberSide;
    printf("Your dice range is %d to %.0lf. \n",NumberRoll ,RangeHigher);
    double Average = ((RangeHigher + NumberRoll)/2);
    printf("The average value is %lf \n",Average);
    return 0;
}
    
    
    
    
