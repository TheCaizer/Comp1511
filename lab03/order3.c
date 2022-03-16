//Jackie Cai order 3 program
//z5259449 1/10/2019

#include<stdio.h>
#include<stdlib.h>

int main(void) {
    int inte1;
    int inte2;
    int inte3;
    printf("Enter integer:");
    scanf("%d",&inte1);
    printf("Enter integer:");
    scanf("%d",&inte2);
    printf("Enter integer:");
    scanf("%d",&inte3);
    if (inte1 <= inte2 &&  inte2 <= inte3){
    printf("The integers in order are: %d %d %d \n",inte1 ,inte2 ,inte3);      
return 0;
}
    else if(inte1 <= inte3 && inte3 <= inte2){
    printf("The integers in order are: %d %d %d \n",inte1 ,inte3 ,inte2);
return 0;
}
  else if (inte2 <= inte1 &&  inte1 <= inte3){
    printf("The integers in order are: %d %d %d \n",inte2 ,inte1 ,inte3);      
return 0;
}
    else if(inte2 <= inte3 && inte3 <= inte1){
    printf("The integers in order are: %d %d %d \n",inte2 ,inte3 ,inte1);
return 0;
}
else if (inte3 <= inte1 &&  inte1 <= inte2){
    printf("The integers in order are: %d %d %d \n",inte3 ,inte1 ,inte2);      
return 0;
}
    else if(inte3 <= inte2 && inte2 <= inte1){
    printf("The integers in order are: %d %d %d \n",inte3 ,inte2 ,inte1);
return 0;
}
}
