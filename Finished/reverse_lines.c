#include <stdio.h>
#include <stdlib.h>

int main(void){
  
  int i = 0;
  char str[256];
  
  int Character = getchar();
  
  while(Character != EOF){
    
    while(Character != '\n'){
      str[i] = Character;
      i++;
      
      Character = getchar();
    }
    
    int j = i - 1;
    while(j >= 0){
      printf("%c", str[j]);
      j--;
    }
    
    i = 0;
    printf("\n");
    Character = getchar();
  }
}
