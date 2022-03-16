#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE 50

// Do not edit this struct. You may use it exactly as it is
// but you cannot make changes to it
struct pokemon {
    char name[MAX_NAME_SIZE];
    struct pokemon *evolution;
};

// Create a pokemon 
struct pokemon *create_pokemon(char name[MAX_NAME_SIZE]) {
    // PUT YOUR CODE HERE (you must change the next line!)
    struct pokemon *poke = malloc(sizeof(struct pokemon));
    strcpy(poke->name,name);
    poke->evolution = NULL;
    return poke;
}

// Link a pokemon to another that it evolves into
void evolve_pokemon(struct pokemon *base, struct pokemon *evolution) {
    // PUT YOUR CODE HERE
    base->evolution = evolution;
}

// Print out the evolution of a pokemon
void print_evolution(struct pokemon *p) {
    // PUT YOUR CODE HERE
    while(p->evolution != NULL){
        printf("%s\n" ,p->name);
        p = p->evolution; 
    }
    if(p->evolution == NULL){
        printf("%s\n" ,p->name);
    }
}

// This is a simple main function which could be used
// to test your pokemon functions.
// It will not be marked.
// Only your pokemon functions will be marked.

int main(void) {
    struct pokemon *pikachu = create_pokemon("Pikachu");
    struct pokemon *raichu = create_pokemon("Raichu");
    evolve_pokemon(pikachu, raichu);
    print_evolution(pikachu);
    return 0;
}
