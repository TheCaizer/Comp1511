// Assignment 2 19T3 COMP1511: Pokedex
// pokedex.c
//
// This program was written by Jackie Cai (z5259449)
// on 14/11/19
//
// Version 2.0.0: Release

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// ----------------------------------------------
// Add any extra #includes your code needs here.
// ----------------------------------------------

#include "pokedex.h"

// ----------------------------------------------
// Add your own #defines here.
// ----------------------------------------------
//Useful throughout code if need binary to define yes or no
#define TRUE 1
#define FALSE 0
//for array size and other size if needed
#define MAX_LENGTH 1000

// Note you are not permitted to use arrays in struct pokedex,
// you must use a linked list.
// The only exception is that char arrays are permitted for
// search_pokemon and functions it may call, as well as the string
// returned by pokemon_name (from pokemon.h).

//curr is the current node, tail is the last node, min_id is the minimum id for
//the pokedex and total node is the number of nodes in the dex
struct pokedex {
    struct pokenode *head;
    struct pokenode *curr;
    struct pokenode *tail;
    int total_node;
    int min_id;
};
//struct next for the next in the list, prev for previous one and evolution for
//their evolution, found to declare if they have been found by trainer or not
struct pokenode {
    Pokemon pokemon;
    struct pokenode *next;
    struct pokenode *prev;
    struct pokenode *evolution;
    int found;
};

//////////////////////////////////////////////////////////////////////
//                       Prototype Functions                        //
//////////////////////////////////////////////////////////////////////
static int check_same_ID(Pokedex pokedex, Pokemon pokemon);
static void add_node_dex(Pokedex pokedex, struct pokenode *node);
static struct pokenode *new_pokenode(Pokemon pokemon);
static void print_not_found(struct pokenode* node);
static void not_found_name(char *name);
static void print_found(struct pokenode* node);
static void print_pokemon_list(Pokedex pokedex, struct pokenode *node);
static struct pokenode *get_pokemon(Pokedex pokedex, int id);
static void evolution_types(Pokemon pokemon);
static void add_dex_type(Pokedex pokedex, Pokedex new_dex, pokemon_type type);
static void tidy_new_dex(Pokedex pokedex);
static void add_new_dex_found(Pokedex pokedex, Pokedex new_dex);
static void order_pokemon(Pokedex pokedex, struct pokenode *node);
static int same_type(struct pokenode *node, pokemon_type type);
static int string_cmp(char *name, char*search);
static void lower(char *string, char *new);
static const char *type_first_string_n(struct pokenode *node);
static const char *type_second_string_n(struct pokenode *node);
static const char *type_first_string_p(Pokemon pokemon);
static const char *type_second_string_p(Pokemon pokemon);

Pokedex new_pokedex(void) {

    // Malloc memory for a new Pokedex, and check that the memory
    // allocation succeeded.
    Pokedex pokedex = malloc(sizeof(struct pokedex));
    assert(pokedex != NULL);

    //initialize the pokedex with no values, since 0 is a valid id
    //-1 would not be valid and therefore initalized but not used
    pokedex->head = NULL;
    pokedex->curr = NULL;
    pokedex->total_node = 0;
    pokedex->min_id = -1;

    return pokedex;
}

static struct pokenode *new_pokenode(Pokemon pokemon) {

    /*allocate memory to store the new pokenode*/
    struct pokenode *new_node = malloc(sizeof(struct pokenode));

    /*check if the new node is NULL which means there's no more memory*/
    if (new_node == NULL){
        printf("No Memory Avaliable!");
    }
    
    /*Since it placed at the end of dex next is NULL,not found yet*/
    new_node->next = NULL;
    new_node->pokemon = pokemon;
    new_node->found = FALSE;
    new_node->evolution = NULL;

    return new_node;
}

//////////////////////////////////////////////////////////////////////
//                         Stage 1 Functions                        //
//////////////////////////////////////////////////////////////////////

// Add a new Pokemon to the Pokedex.
void add_pokemon(Pokedex pokedex, Pokemon pokemon) {
    //Checks if ID already exist
    if (check_same_ID(pokedex, pokemon) == 1) {
        printf("ERROR: ID already exist");
        printf("Exitting program");
        return;
    }
    //makes a new node and then add it to the pokedex.
    struct pokenode *new_node = new_pokenode(pokemon);
    add_node_dex(pokedex, new_node);
}

// Print out the details of the currently selected Pokemon.
void detail_pokemon(Pokedex pokedex) {
    //Check if the dex is empty
    if (pokedex->head == NULL) {
        printf("ERROR: Pokedex is empty!");
        return;
    }
    //assign the current pokenode in the dex as the node we're operating
    struct pokenode *curr_node = pokedex->curr;
    //checks if we found the pokemon or not and print the different result
    if (curr_node->found == FALSE) {
        print_not_found(curr_node);
    }
    else  {
        print_found(curr_node);
    }
}

// Return the currently selected Pokemon.
Pokemon get_current_pokemon(Pokedex pokedex) {
    //check if the pokedex is empty
    if (pokedex->head == NULL) {
        printf("ERROR: Pokdex is empty!");
        exit(1);
    }
    //if not then returns the current node in dex
    else {
        return pokedex->curr->pokemon;
    }
}

// Sets the currently selected Pokemon to be 'found'.
void find_current_pokemon(Pokedex pokedex) {
    //checks if the dex is empty, if not then makes the current node found true
    if (pokedex->head != NULL) {
        pokedex->curr->found = TRUE;
    }
}

// Print out all of the Pokemon in the Pokedex.
void print_pokemon(Pokedex pokedex) {
    //checks if dex is empty if not start function to print the list
    if (pokedex->head != NULL) {
        struct pokenode *node = pokedex->head;
        while (node != NULL) {
            print_pokemon_list(pokedex, node);
            node = node->next;
        }
    }
}

//////////////////////////////////////////////////////////////////////
//                         Stage 2 Functions                        //
//////////////////////////////////////////////////////////////////////

// Change the currently selected Pokemon to be the next Pokemon in the Pokedex.
void next_pokemon(Pokedex pokedex) {
    //checks if the pokdex is empty and there is a next node
    if (pokedex->head != NULL && pokedex->curr->next !=NULL) {
        pokedex->curr = pokedex->curr->next;
    }
}

// Change the currently selected Pokemon to be the previous Pokemon in the dex.
void prev_pokemon(Pokedex pokedex) {
    //same as the next pokemon but add a prev node to track the previous node
    if (pokedex->head != NULL && pokedex->curr->prev !=NULL){
        pokedex->curr = pokedex->curr->prev;
    }
}

// Change the currently selected Pokemon to be the Pokemon with the ID `id`.
void change_current_pokemon(Pokedex pokedex, int id) {
    //checks if the dex is empty
    if (pokedex->head != NULL) {
        struct pokenode *finder = NULL;
        struct pokenode *node = pokedex->head;
        //goes through the dex to find the same id until NULL or it finds it 
        while(finder == NULL && node != NULL) {
            if (pokemon_id(node->pokemon) == id){
                finder = node;
            }
            node = node->next;
        }
        //Once it finds it it puts the current node as the same id given
        if (finder != NULL) {
            pokedex->curr = finder;
        }
    }
}

// Remove the currently selected Pokemon from the Pokedex.
void remove_pokemon(Pokedex pokedex) {
    //checks if the current node is NULL since thats only possible when dex
    //is empty
    if (pokedex->curr == NULL) {
        return;
    }
    //added total node to count the amount of nodes to determine if the dex
    //only contains one entry
    if (pokedex->total_node == 1) {
        //destorys the only node and then sets the dex back to NULL
        destroy_pokemon(pokedex->curr->pokemon);
        free(pokedex->curr);
        pokedex->head = NULL;
        pokedex->tail = NULL;
        pokedex->curr = NULL;
        pokedex->total_node--;
    }
    //checks if the one being removed is the last pokenode
    else if (pokedex->curr == pokedex->tail) {
        //destroys the node and sets the previous node as its current node
        pokedex->curr = pokedex->tail->prev;
        destroy_pokemon(pokedex->tail->pokemon);
        free(pokedex->tail);
        pokedex->curr->next = NULL;
        pokedex->tail = pokedex->curr;
        pokedex->total_node--;
    }
    //checks that there is more than one node and that the current node is the 
    //first node
    else if (pokedex->curr == pokedex->head && pokedex->total_node > 1) {
        pokedex->curr = pokedex->head->next;
        destroy_pokemon(pokedex->head->pokemon);
        free(pokedex->head);
        pokedex->curr->prev = NULL;
        pokedex->head = pokedex->curr;
        pokedex->total_node--;
    }
    //If the node is between nodes we take the node and delete and put the 
    //linked list back together
    else {
        struct pokenode *remove = pokedex->curr;
        pokedex->curr = pokedex->curr->next;
        pokedex->curr->prev = remove->prev;
        pokedex->curr->prev->next = pokedex->curr;
        pokedex->total_node--;
        destroy_pokemon(remove->pokemon);
        free(remove);
    }

}

// Destroy the given Pokedex and free all associated memory.
void destroy_pokedex(Pokedex pokedex) {
    struct pokenode *curr = pokedex->head;
    //goes throgh the list and destroy the pokemon and free them then free
    //the dex
    while(curr != NULL) {
        //make a dummy to store next or would be accessing a freed memory
        struct pokenode *dummy = curr->next;
        destroy_pokemon(curr->pokemon);
        free(curr);
        curr = dummy;
    }
    free(pokedex);
}

//////////////////////////////////////////////////////////////////////
//                         Stage 3 Functions                        //
//////////////////////////////////////////////////////////////////////

// Print out all of the different types of Pokemon in the Pokedex.
void show_types(Pokedex pokedex) {
    //checks if the pokedex is NULL
    if (pokedex->head == NULL){
        return;
    }
    struct pokenode *node = pokedex->head;
    int i = 0;
    int j = 1;
    int checker = 0;
    const char *array[MAX_LENGTH];
    //goes through the list and adds all the types into an array
    while(node != NULL){
        //also counts the size of the array
        array[i] = type_first_string_n(node);
        i++; 
        if (pokemon_second_type(node->pokemon) != NONE_TYPE){
            //also grabs the second type of pokemons
            array[i]=type_second_string_n(node);
            i++;
        }
        node = node->next;
    }
    //checks id the first array is NULL
    if (array[0] != NULL){
        //since the first type is always unique it prints it
        printf("%s\n", array[0]);
        while(j < i){
            if (array[j] == array[checker]){
                //if they find the same type it skips array and moves to next
                j++;
                checker=0;
            }
            else if (array[j] != array[checker]){
                checker++;
                //if not it continues checking until it reaches itself then
                //prints the type and moves onto the next array slot
                if (checker == j){
                    printf("%s\n", array[j]);
                    j++;
                    checker = 0;
                }
            }
        }
    }
}

// Set the first not-yet-found Pokemon of each type to be found.
void go_exploring(Pokedex pokedex) {
    struct pokenode *node = pokedex->head;
    const char *array[MAX_LENGTH];
    const char *cross_check[MAX_LENGTH];
    int i = 0;
    int checker = 0;
    int j = 0;
    int k = 1;
    //check node is not NULL
    if (node == NULL){
        return;
    }
    //takes all the not found pokemon's type
    while(node != NULL){
        if (node->found == FALSE){
            array[i] = type_first_string_n(node);
            i++; 
            if (pokemon_second_type(node->pokemon) != NONE_TYPE){
                //also grabs the second type of pokemons
                array[i] = type_second_string_n(node);
                i++;
            }
        }
        node = node->next;
    }
    //first one is always unique
    cross_check[0] = array[0];
    //finds all unique types and in the order they appear in
    if ( array[0] != NULL){
        while(j < i){
            if (array[j] == array[checker]){
                //if they find the same type it skips array and moves to next
                j++;
                checker=0;
            }
            else if (array[j] != array[checker]){
                checker++;
                //if not it continues checking until it reaches itself then
                //it store's that type into another array if its unique
                if (checker == j){
                    cross_check[k] = array[j];
                    j++;
                    k++;
                    checker = 0;
                }
            }
        }
    }
    //once it has all unique types ,it goes through the list and finds the 
    //first not found pokemon that has that type and marks it as found
    node = pokedex->head;
    i = 0;
    if (cross_check[0] == NULL){
        return;
    }
    while(i < k){
        if (node->found == FALSE){
            //if it finds one that is equal to the type and sets it to TRUE
            if (type_first_string_n(node) == cross_check[i]){
                node->found = TRUE;
                i++;
            }
            //checks the second type of pokemon as well
            if (pokemon_second_type(node->pokemon) != NONE_TYPE && i != k){
                if (type_second_string_n(node) == cross_check[i]){
                    node->found = TRUE;
                    i++;
                }
            }
            
        }
        node = node->next;
    }
}

// Return the total number of Pokemon in the Pokedex.
int count_total_pokemon(Pokedex pokedex) {
    return pokedex->total_node;
}

// Return the number of Pokemon in the Pokedex that have been found.
int count_found_pokemon(Pokedex pokedex) {
    int found_number = 0;
    struct pokenode *node = pokedex->head;
    //goes through the list and finds if the pokemon is found and count
    while(node != NULL){
        if (node->found == TRUE){
            found_number++;
        }
        node = node->next;
    }
    return found_number;
}

//////////////////////////////////////////////////////////////////////
//                         Stage 4 Functions                        //
//////////////////////////////////////////////////////////////////////

// Add the information that the Pokemon with the ID `from_id` can
// evolve into the Pokemon with the ID `to_id`.
void add_pokemon_evolution(Pokedex pokedex, int from_id, int to_id) {
    //first checks if the provided id are the same
    if (from_id == to_id){
        printf("ERROR: Provided ID's are the same");
        return;
    }
    struct pokenode *to_evolution = get_pokemon(pokedex, to_id);
    struct pokenode *base = get_pokemon(pokedex, from_id);
    //checks for NULL id
    if (base == NULL || to_evolution == NULL){
        printf("ERROR: Provided ID does not exist");
    }
    base->evolution = to_evolution;
}

// Show the evolutions of the currently selected Pokemon.
void show_evolutions(Pokedex pokedex) {
    //checks for empty pokedex
    if (pokedex->head == NULL){
        return;
    }
    struct pokenode *curr = pokedex->curr;
    while(curr != NULL){
        printf("#%03d ", pokemon_id(curr->pokemon));
        //determines if the pokemon is found to print name or ???
        if (curr->found == TRUE){
            printf("%s ", pokemon_name(curr->pokemon));
            evolution_types(curr->pokemon);
        }
        else {
            printf("???? [????]");
        }
        //goes through evolution and checks if it has any
        if (curr->evolution != NULL){
            printf(" --> ");
        }
        curr = curr->evolution;
    }
    //prints new line for style after the function ends
    if (pokedex->head != NULL){
        printf("\n");
    }
}

// Return the pokemon_id of the Pokemon that the currently selected
// Pokemon evolves into.
int get_next_evolution(Pokedex pokedex) {
    //check for empty dex
    if (pokedex->head == NULL) {
        printf("Pokedex is empty. Can't get next evolution\n");
        return 1;
    }
    //if the pokemon does not evolve it returns the DOES_NOT_EVOLVE
    if (pokedex->curr->evolution == NULL) {
        return DOES_NOT_EVOLVE;
    }
    //if it does it returns what it evolves into
    return pokemon_id(pokedex->curr->evolution->pokemon);
}

//////////////////////////////////////////////////////////////////////
//                         Stage 5 Functions                        //
//////////////////////////////////////////////////////////////////////

// Create a new Pokedex which contains only the Pokemon of a specified
// type from the original Pokedex.
Pokedex get_pokemon_of_type(Pokedex pokedex, pokemon_type type) {
    //checks for the invalid types
    if (type == NONE_TYPE || type <= INVALID_TYPE || type >= MAX_TYPE){
        printf("ERROR: Invalid type entered");
        exit(1);
    }
    Pokedex new_dex = new_pokedex();
    //dont need to change current pointer as the add pokemon in the function
    //will set the first pokemon as the current one
    add_dex_type(pokedex, new_dex, type);
    tidy_new_dex(new_dex);
    return new_dex;

}

// Create a new Pokedex which contains only the Pokemon that have
// previously been 'found' from the original Pokedex.
Pokedex get_found_pokemon(Pokedex pokedex) {
    Pokedex new_dex = new_pokedex();
    add_new_dex_found(pokedex, new_dex);
    //makes sure that the pokemon does not have evolution
    tidy_new_dex(new_dex);
    return new_dex;
}

// Create a new Pokedex containing only the Pokemon from the original
// Pokedex which have the given string appearing in its name.
Pokedex search_pokemon(Pokedex pokedex, char *text) {
    Pokedex new_dex = new_pokedex();
    struct pokenode *node = pokedex->head;
    //Goes through the pokedex and clones pokemon that have the text in the
    //and also that it is found
    while(node != NULL){
        if (string_cmp(pokemon_name(node->pokemon), text) && node->found == 1){
            Pokemon new_pokemon = clone_pokemon(node->pokemon);
            add_pokemon(new_dex, new_pokemon);
        }
        node = node->next;
    }
    tidy_new_dex(new_dex);
    return new_dex;
}

//////////////////////////////////////////////////////////////////////
//                         My Functions                             //
//////////////////////////////////////////////////////////////////////

//A helper function that checks every node in dex with the one given for dupes
//If a dupe exist it sends message and exit program
static int check_same_ID(Pokedex pokedex, Pokemon pokemon){
    struct pokenode *curr = pokedex->head;
    int checker = FALSE;
    while(curr != NULL){
        //checks if the id are the same if not it moves to next node
        if (pokemon_id(curr->pokemon) == pokemon_id(pokemon)){
            checker = TRUE;
        }
        else {
            curr = curr->next;
        }
    }
    return checker;
}

//This function adds the node to the pokedex, first checks if there is a node,
//if so it adds it to the pokdex as the first and the current node. If not
//the previous added node will add the new node next to it, increases the node 
//count for the dex.
static void add_node_dex(Pokedex pokedex, struct pokenode *node){
    if (pokedex->head == NULL){
        pokedex->head = node;
        node->prev = NULL;
        pokedex->curr = pokedex->head;
        pokedex->min_id = pokemon_id(node->pokemon);
    }
    else {
        node->prev = pokedex->tail;
        pokedex->tail->next = node;
        if (pokedex->min_id > pokemon_id(node->pokemon)) {
            pokedex->min_id = pokemon_id(node->pokemon);
        }
    }
    pokedex->tail = node;
    pokedex->total_node++;
}

//prints out a pokemon that has not been found.
static void print_not_found(struct pokenode* node){
    int id = pokemon_id(node->pokemon);

    printf("ID: %03d\n", id);
    printf("Name: ");
    not_found_name(pokemon_name(node->pokemon));
    printf("Height: --\n");
    printf("Weight: --\n");
    printf("Type: --\n");
}

//not_found_name prints out the name of the pokemon but censored with '*'
static void not_found_name(char *name){
    int i = 0;
    //goes through the name until null terminator and prints '*' depending on
    //the length of the name
    while (name[i] != '\0'){
        printf("*");
        i++;
    }
    printf("\n");
}

//prints out found pokemon's stats
static void print_found(struct pokenode* node){

    int id = pokemon_id(node->pokemon);
    char *name = pokemon_name(node->pokemon);
    double height = pokemon_height(node->pokemon);
    double weight = pokemon_weight(node->pokemon);
    pokemon_type first_type = pokemon_first_type(node->pokemon);
    pokemon_type second_type = pokemon_second_type(node->pokemon);
    //prints all the information of the pokemon 
    printf("ID: %03d\n", id);
    printf("Name: %s\n", name);
    printf("Height: %.1lfm\n", height);
    printf("Weight: %.1lfkg\n", weight);
    printf("Type: %s", pokemon_type_to_string(first_type));
    //checks if a second type exist if so then prints it
    if (second_type != NONE_TYPE){
        printf(" %s", pokemon_type_to_string(second_type));

    }
    printf("\n");
}

//prints the pokedex as a list in the format of the ID and the name and
//depending if it's found then censor it or not
static void print_pokemon_list(Pokedex pokedex, struct pokenode *node){
    int id = pokemon_id(node->pokemon);
    char *name = pokemon_name(node->pokemon);
    if (pokedex->curr == node){
        printf("--> ");
    }
    else {
        printf("    ");
    }
    printf("#%03d: ", id);
    if (node->found == FALSE) {
        not_found_name(name);
    } else  {
        printf("%s\n", name);
    }
}
//cehcks the dex until it finds the ID or it doesnt find it
static struct pokenode *get_pokemon(Pokedex pokedex, int id){
    struct pokenode *node = pokedex->head;
    while(node != NULL){
        if (pokemon_id(node->pokemon) == id){
            return node;
        }
        else {
            node = node->next;
        }
    }
    return NULL;
}

//prints the pokemon type in show evolution
static void evolution_types(Pokemon pokemon) {
    const char *first_type = type_first_string_p(pokemon);
    const char *second_type = type_second_string_p(pokemon);
    //checkers for one or two type
    if (pokemon_second_type(pokemon) != NONE_TYPE) {
        printf("[%s %s]", first_type, second_type);
    } else  {
        printf("[%s]", first_type);
    }
    return;
}
//adds pokemon to dex that are found and matches a certain type
static void add_dex_type(Pokedex pokedex, Pokedex new_dex, pokemon_type type){
    struct pokenode *node = pokedex->head;
    while(node != NULL) {
        //check for same type as well as found
        if (same_type(node, type) && node->found){
            add_pokemon(new_dex, clone_pokemon(node->pokemon));
        }
        node = node->next;
    }
}

//checks node has a specific given type
static int same_type(struct pokenode *node, pokemon_type type){
    if (pokemon_first_type(node->pokemon) == type){
        return TRUE;
    }
    else if (pokemon_second_type(node->pokemon) != NONE_TYPE){
        if (pokemon_second_type(node->pokemon) == type) {
            return TRUE;
        }
    }
    else  {
        return FALSE;
    }
    return 0;
}

//this function removes all evolution node and marks all pokemon as found
static void tidy_new_dex(Pokedex pokedex){
    struct pokenode *node = pokedex->head;
    while(node != NULL){
        node->evolution = NULL;
        node->found = TRUE;
        node = node->next;
    }
}

//adds pokemon that are found to the dex
static void add_new_dex_found(Pokedex pokedex, Pokedex new_dex){
    struct pokenode *head = pokedex->head;
    while(head != NULL) {
        //check for found and creates a new node for them
        if (head->found){
            struct pokenode *node = new_pokenode(clone_pokemon(head->pokemon));
            //then orders them in ascending order
            order_pokemon(new_dex, node);
        }
        head = head->next;
    }
}

//orders the pokemon in ascending order
static void order_pokemon(Pokedex pokedex, struct pokenode *node){
    //If the dex is empty we add the first node as it is
    if (pokedex->total_node == 0){
        pokedex->head = node;
        node->prev = NULL;
        pokedex->curr = pokedex->head;
        pokedex->min_id = pokemon_id(node->pokemon);
    }
    else  {
        if (pokemon_id(node->pokemon) < pokemon_id(pokedex->head->pokemon)){
            //if the added pokemon has an ID lower than the head of the pokemon
            //then it sets the dex in order
            node->next = pokedex->head;
            pokedex->head = node;
            node->next->prev = node;
            pokedex->curr = node;
            pokedex->min_id = pokemon_id(node->pokemon);
        }
        else  {
            //If the id is greater than the head than it starts ordering it
            struct pokenode *new = pokedex->head;
            //checks its not NULL and the id is less than the node, swaps node
            while(new->next != NULL && (pokemon_id(node->pokemon) > 
            pokemon_id(new->next->pokemon))) {
                new = new->next;
            }
            //swaps the position of new and node
            node->next = new->next;
            new->next = node;
            node->prev = new;

            //check if the node is the last node and if so sets it as tail
            //if not then set the next node after that as the new node
            if (node->next == NULL) {
                pokedex->tail = node;
            } else  {
                node->next->prev = node;
            }
        }
    }
    //count number of nodes
    pokedex->total_node++;
}
//compares the string of the pokemon with the given text to determine if the
//text is in the string
static int string_cmp(char *name, char*search){
    int check = FALSE;
    char lower_name[MAX_LENGTH];
    char lower_search[MAX_LENGTH];
    lower(name, lower_name);
    lower(search, lower_search);
    int i = 0;
    //finds the first character
    while(lower_name[i] != '\0' && check == FALSE){
        //compares the rest of the name
        int exit = 0;
        int j = 0;
        while(lower_search[j] != '\0' && exit == 0){
            //if it doesnt match it ends the loop
            if (lower_search[j] != lower_name[i + j]) {
                exit = 1;
            }
            j++;
        }
        //if the loop continued to the end it means that the name is match
        if (exit == 0) {
            check = TRUE;
        }
        i++;
    }
    return check;
}
//copys a string into the function to use to lower case it so it can operate 
//with it, without changing the original case of name
static void lower(char *string, char *new){
    int i =0;
    while(string[i] != '\0'){
        if (string[i] >= 'A' && string[i] <= 'Z') {
            new[i] = string[i] + ('a' - 'A');
        } else  {
            new[i] = string[i];
        }
        i++;
    }
    new[i] = '\0';
    return;
}
//new function convert type to string to make it shorter for nodes
static const char *type_first_string_n(struct pokenode *node){
    const char *type1;
    type1 = pokemon_type_to_string(pokemon_first_type(node->pokemon));
    return type1;
}

static const char *type_second_string_n(struct pokenode *node){
    const char *type2;
    type2 = pokemon_type_to_string(pokemon_second_type(node->pokemon));
    return type2;
}
//same as the previous one but pass through a Pokemon instead
static const char *type_first_string_p(Pokemon pokemon){
    const char *type1;
    type1 = pokemon_type_to_string(pokemon_second_type(pokemon));
    return type1;
}

static const char *type_second_string_p(Pokemon pokemon){
    const char *type2;
    type2 = pokemon_type_to_string(pokemon_second_type(pokemon));
    return type2;
}