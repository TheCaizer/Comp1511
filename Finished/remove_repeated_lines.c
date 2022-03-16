#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  
    int i = 0;
    int j = 0;
    int dupe = 0;
    char string[256][256];
    
    // Read line of input
    while (fgets(string[i], 256, stdin) != NULL) {
      
      if (i == 0) {
          printf("%s",string[i]);
      }
      
      // Checking for dupes
      while (j < i) {
          if (i > 0) {
            
              if (strcmp(string[j], string[i]) == 0) {
                  dupe = 1;
              }
              if (j == i - 1 && dupe != 1) {
                  printf("%s", string[i]);
              }
              j++;
          }
      }
      
      i++;
      j = 0;
      
      dupe = 0;
  }
  
  return 0;
}

