// Assignment 2 19T3 COMP1511: Pokedex
// test_pokedex.c
//
// This file allows you to automatically test the functions you
// implement in pokedex.c.
//
// This program was written by Jackie Cai (z5259449)
// on 23/11/19
//
// Version 1.0.0: Assignment released.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "pokedex.h"

// Add your own #defines here.


// Sample data on Bulbasaur, the Pokemon with pokemon_id 1.
#define BULBASAUR_ID 1
#define BULBASAUR_NAME "Bulbasaur"
#define BULBASAUR_HEIGHT 0.7
#define BULBASAUR_WEIGHT 6.9
#define BULBASAUR_FIRST_TYPE GRASS_TYPE
#define BULBASAUR_SECOND_TYPE POISON_TYPE

// Sample data on Ivysaur, the Pokemon with pokemon_id 2.
#define IVYSAUR_ID 2
#define IVYSAUR_NAME "Ivysaur"
#define IVYSAUR_HEIGHT 1.0
#define IVYSAUR_WEIGHT 13.0
#define IVYSAUR_FIRST_TYPE GRASS_TYPE
#define IVYSAUR_SECOND_TYPE POISON_TYPE
//Added Venasaur to test out 2 evolution
#define VENASAUR_ID 3
#define VENASAUR_NAME "Venasaur"
#define VENASAUR_HEIGHT 10.0
#define VENASAUR_WEIGHT 130.0
#define VENASAUR_FIRST_TYPE GRASS_TYPE
#define VENASAUR_SECOND_TYPE DRAGON_TYPE

#define DRATINI_ID 4
#define DRATINI_NAME "Dratini"
#define DRATINI_HEIGHT 1.0
#define DRATINI_WEIGHT 12.0
#define DRATINI_FIRST_TYPE DRAGON_TYPE
#define DRATINI_SECOND_TYPE NONE_TYPE

#define DRAGONAIR_ID 5
#define DRAGONAIR_NAME "Dragonair"
#define DRAGONAIR_HEIGHT 100.0
#define DRAGONAIR_WEIGHT 130.0
#define DRAGONAIR_FIRST_TYPE DRAGON_TYPE
#define DRAGONAIR_SECOND_TYPE NONE_TYPE

#define DRAGONITE_ID 6
#define DRAGONITE_NAME "Dragonite"
#define DRAGONITE_HEIGHT 10.0
#define DRAGONITE_WEIGHT 130.0
#define DRAGONITE_FIRST_TYPE DRAGON_TYPE
#define DRAGONITE_SECOND_TYPE FLYING_TYPE

#define PIKACHU_ID 7
#define PIKACHU_NAME "Pikachu"
#define PIKACHU_HEIGHT 3.0
#define PIKACHU_WEIGHT 6.0
#define PIKACHU_FIRST_TYPE ELECTRIC_TYPE
#define PIKACHU_SECOND_TYPE NONE_TYPE

//mix of capital and lowercase
#define MEW_ID 90
#define MEW_NAME "MeW"
#define MEW_HEIGHT 1.0
#define MEW_WEIGHT 1.1
#define MEW_FIRST_TYPE PSYCHIC_TYPE
#define MEW_SECOND_TYPE NONE_TYPE
//name has more capitals to test lower function and other function
#define MEWTWO_ID 900
#define MEWTWO_NAME "MEWTWO"
#define MEWTWO_HEIGHT 10.22
#define MEWTWO_WEIGHT 10.6
#define MEWTWO_FIRST_TYPE PSYCHIC_TYPE
#define MEWTWO_SECOND_TYPE NORMAL_TYPE

//standard defines if needed
#define TRUE 1
#define FALSE 0
// Add your own prototypes here.


// Tests for Pokedex functions from pokedex.c.
static void test_new_pokedex(void);
static void test_add_pokemon(void);
static void test_get_found_pokemon(void);
static void test_next_pokemon(void);
static void test_one_pokemon(void);
static void test_empty_pokedex(void);
static void test_pokedex_head(void);
static void test_pokedex_tail(void);
static void test_evolution_overwrite(void);
static void test_go_exploring(void);
static void test_multiple_evolution(void);
static void test_subdex_evolution(void);
static void test_subdex_removal(void); 

// Helper functions for creating/comparing Pokemon.
static Pokemon create_bulbasaur(void);
static Pokemon create_ivysaur(void);
static Pokemon create_venasaur(void);
static Pokemon create_mew(void);
static Pokemon create_mewtwo(void);
static Pokemon create_dratini(void);
static Pokemon create_dragonair(void);
static Pokemon create_dragonite(void);
static Pokemon create_pikachu(void);
static int is_same_pokemon(Pokemon first, Pokemon second);
static int is_copied_pokemon(Pokemon first, Pokemon second);
static void run_current_check(Pokedex pokedex, Pokemon pokemon);



int main(int argc, char *argv[]) {
    printf("Welcome to the COMP1511 Pokedex Tests!\n");

    printf("\n==================== Pokedex Tests ====================\n");

    test_new_pokedex();
    test_add_pokemon();
    test_next_pokemon();
    test_get_found_pokemon();
    test_empty_pokedex();
    test_one_pokemon();
    test_pokedex_head();
    test_pokedex_tail();
    test_evolution_overwrite();
    test_go_exploring();
    test_multiple_evolution();
    test_subdex_evolution();
    test_subdex_removal();

    printf("\nAll Pokedex tests passed, you are Awesome!\n");
}


////////////////////////////////////////////////////////////////////////
//                     Pokedex Test Functions                         //
////////////////////////////////////////////////////////////////////////

// `test_new_pokedex` checks whether the new_pokedex and destroy_pokedex
// functions work correctly, to the extent that it can.
//
// It does this by creating a new Pokedex, checking that it's not NULL,
// then calling destroy_pokedex.
//
// Note that it isn't possible to check whether destroy_pokedex has
// successfully destroyed/freed the Pokedex, so the best we can do is to
// call the function and make sure that it doesn't crash..
static void test_new_pokedex(void) {
    printf("\n>> Testing new_pokedex\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("       --> Checking that the returned Pokedex is not NULL\n");
    assert(pokedex != NULL);

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed new_pokedex tests!\n");
}

// `test_add_pokemon` checks whether the add_pokemon function works
// correctly.
//
// It does this by creating the Pokemon Bulbasaur (using the helper
// functions in this file and the provided code in pokemon.c), and
// calling add_pokemon to add it to the Pokedex.
//
// Some of the ways that you could extend these test would include:
//   - checking whether the currently selected Pokemon is correctly set,
//   - checking that functions such as `count_total_pokemon` return the
//     correct result after more Pokemon are added,
//   - ... and more!
static void test_add_pokemon(void) {
    printf("\n>> Testing add_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("       --> Checking that the returned Pokedex is not NULL\n");
    assert(pokedex != NULL);

    printf("    ... Creating Bulbasaur\n");
    Pokemon bulbasaur = create_bulbasaur();

    printf("    ... Creating Ivysaur\n");
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Creating Venasaur\n");
    Pokemon venasaur = create_venasaur();

    printf("    ... Creating Mew\n");
    Pokemon mew = create_mew();

    printf("    ... Creating Mewtwo\n");
    Pokemon mewtwo = create_mewtwo();

    printf("    ... Adding Bulbasaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    assert(count_total_pokemon(pokedex) == 1);

    printf("    ... Adding Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, ivysaur);
    assert(count_total_pokemon(pokedex) == 2);

    printf("    ... Adding Venasaur to the Pokedex\n");
    add_pokemon(pokedex, venasaur);
    assert(count_total_pokemon(pokedex) == 3);

    printf("    ... Adding Mew to the Pokedex\n");
    add_pokemon(pokedex, mew);

    printf("    ... Adding Mewtwo to the Pokedex\n");
    add_pokemon(pokedex, mewtwo);
    assert(count_total_pokemon(pokedex) == 5);

    printf("    ... Testing current pokemon is Bulbasaur\n");
    run_current_check(pokedex, bulbasaur);

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed add_pokemon tests!\n");
}

// `test_next_pokemon` checks whether the next_pokemon function works
// correctly.
//
// It does this by creating two Pokemon: Bulbasaur and Ivysaur (using
// the helper functions in this file and the provided code in pokemon.c).
//
// It then adds these to the Pokedex, then checks that calling the
// next_pokemon function changes the currently selected Pokemon from
// Bulbasaur to Ivysaur.
//
// Some of the ways that you could extend these tests would include:
//   - adding even more Pokemon to the Pokedex,
//   - calling the next_pokemon function when there is no "next" Pokemon,
//   - calling the next_pokemon function when there are no Pokemon in
//     the Pokedex,
//   - ... and more!
static void test_next_pokemon(void) {
    printf("\n>> Testing next_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    assert(count_total_pokemon(pokedex) == 2);

    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));

    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);

    printf("       --> Checking that the current Pokemon is Ivysaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), ivysaur));

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed next_pokemon tests!\n");
}

// `test_get_found_pokemon` checks whether the get_found_pokemon
// function works correctly.
//
// It does this by creating two Pokemon: Bulbasaur and Ivysaur (using
// the helper functions in this file and the provided code in pokemon.c).
//
// It then adds these to the Pokedex, sets Bulbasaur to be found, and
// then calls the get_found_pokemon function to get all of the Pokemon
// which have been found (which should be just the one, Bulbasaur).
//
// Some of the ways that you could extend these tests would include:
//   - calling the get_found_pokemon function on an empty Pokedex,
//   - calling the get_found_pokemon function on a Pokedex where none of
//     the Pokemon have been found,
//   - checking that the Pokemon in the new Pokedex are in ascending
//     order of pokemon_id (regardless of the order that they appeared
//     in the original Pokedex),
//   - checking that the currently selected Pokemon in the returned
//     Pokedex has been set correctly,
//   - checking that the original Pokedex has not been modified,
//   - ... and more!
static void test_get_found_pokemon(void) {
    printf("\n>> Testing get_found_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);

    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(get_current_pokemon(pokedex) == bulbasaur);
    
    printf("    ... Setting Bulbasaur to be found\n");
    find_current_pokemon(pokedex);

    printf("    ... Getting all found Pokemon\n");
    Pokedex found_pokedex = get_found_pokemon(pokedex);

    printf("       --> Checking the correct Pokemon were copied and returned\n");
    assert(count_total_pokemon(found_pokedex) == 1);
    assert(count_found_pokemon(found_pokedex) == 1);
    assert(is_copied_pokemon(get_current_pokemon(found_pokedex), bulbasaur));

    printf("    ... Destroying both Pokedexes\n");
    destroy_pokedex(pokedex);
    destroy_pokedex(found_pokedex);

    printf(">> Passed get_found_pokemon tests!\n");
}


//test when the pokedex is empty and does not exit when it shouldnt
static void test_empty_pokedex(void) {

    printf("\n>> Testing functions on an empty Pokédex.\n");

    printf("    ... Creating the empty Pokédex.\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Detailing a non-existent Pokémon.\n");
    detail_pokemon(pokedex);

    printf("    ... Printing a non-existent list of Pokémon.\n");
    print_pokemon(pokedex);

    printf("    ... Navigating forwards to a non-existent Pokémon.\n");
    next_pokemon(pokedex);

    printf("    ... Navigating backwards to a non-existent Pokémon.\n");
    prev_pokemon(pokedex);

    printf("    ... Navigating to the non-existent Pokémon with ID: 100.\n");
    change_current_pokemon(pokedex, 100);

    printf("    ... Remove current, non-existent Pokémon.\n");
    remove_pokemon(pokedex);

    printf("    ... Ensuring the number of found Pokémon is 0.\n");
    assert(count_found_pokemon(pokedex) == 0);

    printf("    ... Ensuring the total number of Pokémon is 0.\n");
    assert(count_total_pokemon(pokedex) == 0);

    printf("    ... Showing the evolutions of a non-existent Pokémon.\n");
    show_evolutions(pokedex);

    printf("    ... Ensuring the next evolution of a empty Pokedex exits program.\n");
    assert(get_next_evolution(pokedex) == 1);

    printf("    ... Creating a Pokédex of Psychic type Pokémon.\n");
    Pokedex psychicDex = get_pokemon_of_type(pokedex, PSYCHIC_TYPE);

    printf("    ... Destroying the Pokédex of Psychic type Pokémon.\n");
    destroy_pokedex(psychicDex);

    printf("    ... Creating a Pokédex of found Pokémon.\n");
    Pokedex foundDex = get_found_pokemon(pokedex);

    printf("    ... Destroying the Pokédex of found Pokémon.\n");
    destroy_pokedex(foundDex);

    printf("    ... Creating a Pokédex of Pokémon with the letter 'A'.\n");
    Pokedex searchDex = search_pokemon(pokedex, "A");

    printf("    ... Destroying the Pokédex of found Pokémon.\n");
    destroy_pokedex(searchDex);

    printf("    ... Destroying the empty Pokédex.\n");
    destroy_pokedex(pokedex);

    printf(">> Passed empty Pokédex tests!\n");
}
//Testing when there are only one pokemon in the Pokedex
static void test_one_pokemon(void) {

    printf("\n>> Testing functions on a Pokédex with one Pokémon.\n");

    printf("    ... Creating a Pokédex.\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating a Mew.\n");
    Pokemon mew = create_mew();

    printf("    ... Adding Mew to the Pokédex.\n");
    add_pokemon(pokedex, mew);

    printf("    ... Detailing Mew (CENSORED).\n\n");
    detail_pokemon(pokedex);

    printf("\n    ... Getting current Pokémon, i.e., Mew.\n");
    get_current_pokemon(pokedex);

    printf("    ... Finding current Pokémon.\n");
    find_current_pokemon(pokedex);
    assert(count_found_pokemon(pokedex) == 1);

    printf("    ... Printing a list with only Mew.\n");
    print_pokemon(pokedex);

    printf("    ... Navigating forwards to a non-existent Pokémon.\n");
    next_pokemon(pokedex);
    assert(get_current_pokemon(pokedex) == mew);

    printf("    ... Navigating backwards to a non-existent Pokémon.\n");
    prev_pokemon(pokedex);
    assert(get_current_pokemon(pokedex) == mew);

    printf("    ... Navigating to the non-existent Pokémon with ID: 20.\n");
    change_current_pokemon(pokedex, 20);
    assert(get_current_pokemon(pokedex) == mew);

    printf("    ... Remove Mew.\n");
    remove_pokemon(pokedex);
    assert(count_total_pokemon(pokedex) == 0);

    printf("    ... Adding Mew, and finding it.\n");
    Pokemon Mew = create_mew();
    add_pokemon(pokedex, Mew);
    find_current_pokemon(pokedex);

    printf("    ... Ensuring the number of found Pokémon is 1.\n");
    assert(count_found_pokemon(pokedex) == 1);

    printf("    ... Ensuring the total number of Pokémon is 1.\n");
    assert(count_total_pokemon(pokedex) == 1);

    printf("    ... Adding Mewtwo and finding it.\n");
    Pokemon Mewtwo = create_mewtwo();
    add_pokemon(pokedex, Mewtwo);
    next_pokemon(pokedex);
    find_current_pokemon(pokedex);
    prev_pokemon(pokedex);
    assert(count_total_pokemon(pokedex) == 2);

    printf("    ... Setting the Mewtwo as the evolution.\n");
    add_pokemon_evolution(pokedex, MEW_ID, MEWTWO_ID);
    assert(get_next_evolution(pokedex) != DOES_NOT_EVOLVE);

    printf("    ... Showing the evolutions of Mew.\n\n");
    show_evolutions(pokedex);

    printf("\n    ... Ensuring the next evolution of a non-existent Pokémon is not DOES_NOT_EVOLVE.\n");
    assert(get_next_evolution(pokedex) != DOES_NOT_EVOLVE);

    printf("    ... Destroying the Pokedex.\n");
    destroy_pokedex(pokedex);

    printf(">> Passed single Pokémon tests!\n");
}
//Test the applications of pokedex head and moving around it
static void test_pokedex_head(void) {

    printf("\n>> Testing functions on the head of Pokédex.\n");

    printf("    ... Creating a Pokédex.\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur\n");
    Pokemon bulbasaur = create_bulbasaur();

    printf("    ... Creating Ivysaur\n");
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Creating Venasaur\n");
    Pokemon venasaur = create_venasaur();

    printf("    ... Creating Mew\n");
    Pokemon mew = create_mew();

    printf("    ... Creating Mewtwo\n");
    Pokemon mewtwo = create_mewtwo();

    printf("    ... Adding Bulbasaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);

    printf("    ... Adding Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, ivysaur);

    printf("    ... Adding Venasaur to the Pokedex\n");
    add_pokemon(pokedex, venasaur);

    printf("    ... Adding Mew to the Pokedex\n");
    add_pokemon(pokedex, mew);

    printf("    ... Adding Mewtwo to the Pokedex\n");
    add_pokemon(pokedex, mewtwo);

    printf("    ... Ensuring the selected Pokémon is the first.\n");
    assert(get_current_pokemon(pokedex) == bulbasaur);

    printf("    ... Navigating backwards to a non-existent Pokémon.\n");
    prev_pokemon(pokedex);
    assert(get_current_pokemon(pokedex) == bulbasaur);

    printf("    ... Navigating forwards to the next Pokémon.\n");
    next_pokemon(pokedex);
    assert(get_current_pokemon(pokedex) == ivysaur);

    printf("    ... Removing the first Pokémon (Bulbasaur).\n");
    prev_pokemon(pokedex);
    remove_pokemon(pokedex);

    printf("    ... Ensuring that Ivysaur is selected.\n");
    assert(get_current_pokemon(pokedex) == ivysaur);

    printf("    ... Destroying the Pokédex.\n");
    destroy_pokedex(pokedex);

    printf(">> Passed Pokedex head tests!\n");
}
//Testing the applications of pokedex tail and manipulating it
static void test_pokedex_tail(void) {

    printf("\n>> Testing functions on Pokedex tail.\n");

    printf("    ... Creating a Pokédex.\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur\n");
    Pokemon bulbasaur = create_bulbasaur();

    printf("    ... Creating Ivysaur\n");
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Creating Venasaur\n");
    Pokemon venasaur = create_venasaur();

    printf("    ... Creating Mew\n");
    Pokemon mew = create_mew();

    printf("    ... Creating Mewtwo\n");
    Pokemon mewtwo = create_mewtwo();

    printf("    ... Adding Bulbasaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);

    printf("    ... Adding Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, ivysaur);

    printf("    ... Adding Venasaur to the Pokedex\n");
    add_pokemon(pokedex, venasaur);

    printf("    ... Adding Mew to the Pokedex\n");
    add_pokemon(pokedex, mew);

    printf("    ... Adding Mewtwo to the Pokedex\n");
    add_pokemon(pokedex, mewtwo);

    printf("    ... Moving to the last Pokémon (Mewtwo).\n");
    change_current_pokemon(pokedex, 900);

    printf("    ... Ensuring the last Pokémon has the ID: #900.\n");
    assert(get_current_pokemon(pokedex) == mewtwo);

    printf("    ... Navigating forwards to a non-existent Pokémon.\n");
    next_pokemon(pokedex);
    assert(get_current_pokemon(pokedex) == mewtwo);

    printf("    ... Navigating backwards to the previous Pokémon.\n");
    prev_pokemon(pokedex);
    assert(get_current_pokemon(pokedex) == mew);

    printf("    ... Removing the last Pokémon (Mewtwo).\n");
    next_pokemon(pokedex);
    remove_pokemon(pokedex);

    printf("    ... Ensuring there is 4 Pokémon and that #090 is selected.\n");
    assert(count_total_pokemon(pokedex) == 4);
    assert(get_current_pokemon(pokedex) == mew);

    printf("    ... Destroying the Pokédex.\n");
    destroy_pokedex(pokedex);

    printf(">> Passed pokedex tail tests!\n");
}
//Testing if the evolution of Pokemon is overwritten if used multiple times
static void test_evolution_overwrite(void) {

    printf("\n>> Testing evolution overwriting.\n");

    printf("    ... Creating a new Pokédex.\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Creating Bulbasaur\n");
    Pokemon bulbasaur = create_bulbasaur();

    printf("    ... Creating Ivysaur\n");
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Creating Venasaur\n");
    Pokemon venasaur = create_venasaur();
    
    printf("    ... Adding Bulbasaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    assert(count_total_pokemon(pokedex) == 1);

    printf("    ... Adding Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, ivysaur);
    assert(count_total_pokemon(pokedex) == 2);

    printf("    ... Adding Venasaur to the Pokedex\n");
    add_pokemon(pokedex, venasaur);
    assert(count_total_pokemon(pokedex) == 3);
    
    printf("    ... Creating the evolution: #001 --> #002.\n");
    add_pokemon_evolution(pokedex,1,2);

    printf("    ... Creating the evolution: #001 --> #003.\n");
    add_pokemon_evolution(pokedex,1,3);

    printf("    ... Checking to see if the evolution was overwritten.\n");
    assert(get_next_evolution(pokedex) == 3);

    printf("\n   ... Destroying the Pokedex.\n");
    destroy_pokedex(pokedex);

    printf("\n>> Passed evolution overwrite testing!\n");
}
//Test when there are only found pokemon in go expoloring it does nothing
static void test_go_exploring(void){
    printf("\n>> Testing go exploring.\n");

    printf("    ... Creating a Pokédex.\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur\n");
    Pokemon bulbasaur = create_bulbasaur();

    printf("    ... Creating Ivysaur\n");
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Creating Venasaur\n");
    Pokemon venasaur = create_venasaur();

    printf("    ... Adding Bulbasaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);

    printf("    ... Adding Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, ivysaur);

    printf("    ... Adding Venasaur to the Pokedex\n");
    add_pokemon(pokedex, venasaur);
    
    int i = 0;
    while(i < 3){
        find_current_pokemon(pokedex);
        i++;
    }

    go_exploring(pokedex);

    printf("\n>> Passed go exploring testing!\n");
}
//test what happened to multiple evolutions
static void test_multiple_evolution(void) {

    printf("\n>> Testing long evolution chains.\n");

    printf("    ... Creating a new original Pokédex.\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur\n");
    Pokemon bulbasaur = create_bulbasaur();

    printf("    ... Creating Ivysaur\n");
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Creating Venasaur\n");
    Pokemon venasaur = create_venasaur();

    printf("    ... Creating Mew\n");
    Pokemon mew = create_mew();

    printf("    ... Creating Mewtwo\n");
    Pokemon mewtwo = create_mewtwo();

    printf("    ... Adding Bulbasaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    assert(count_total_pokemon(pokedex) == 1);

    printf("    ... Adding Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, ivysaur);
    assert(count_total_pokemon(pokedex) == 2);

    printf("    ... Adding Venasaur to the Pokedex\n");
    add_pokemon(pokedex, venasaur);
    assert(count_total_pokemon(pokedex) == 3);

    printf("    ... Adding Mew to the Pokedex\n");
    add_pokemon(pokedex, mew);

    printf("    ... Adding Mewtwo to the Pokedex\n");
    add_pokemon(pokedex, mewtwo);
    assert(count_total_pokemon(pokedex) == 5);

    printf("    ... Finding every Pokémon.\n");
    int i = 0;
    while(i < 5){
        find_current_pokemon(pokedex);
        next_pokemon(pokedex);
        i++;
    }
    int i = 0;
    printf("    ... Chaining together evolutions.\n");
    while(i < 5){
        add_pokemon_evolution(pokedex, i, i+1);
        i++;
    }
    printf("    ... Here's the result!\n\n");
    change_current_pokemon(pokedex, 1);
    show_evolutions(pokedex);

    printf("\n   ... Destroying the Pokedex.\n");
    destroy_pokedex(pokedex);

    printf("\n>> Passed multiple evolution chain testing!\n");
}
//test if tidy dex does remove the evolutions from the new dex made
static void test_subdex_evolution(void) {

    printf("\n>> Testing SubDex evolution behavious.\n");

    printf("    ... Creating a new original Pokédex.\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur\n");
    Pokemon bulbasaur = create_bulbasaur();

    printf("    ... Creating Ivysaur\n");
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Creating Venasaur\n");
    Pokemon venasaur = create_venasaur();

    printf("    ... Creating Mew\n");
    Pokemon mew = create_mew();

    printf("    ... Creating Mewtwo\n");
    Pokemon mewtwo = create_mewtwo();

    printf("    ... Creating Dratini\n");
    Pokemon dratini = create_dratini();

    printf("    ... Creating Dragonair\n");
    Pokemon dragonair = create_dragonair();

    printf("    ... Creating Dragonite\n");
    Pokemon dragonite = create_dragonite();

    printf("    ... Creating Pikachu\n");
    Pokemon pikachu = create_pikachu();

    printf("    ... Adding Bulbasaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    assert(count_total_pokemon(pokedex) == 1);

    printf("    ... Adding Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, ivysaur);
    assert(count_total_pokemon(pokedex) == 2);

    printf("    ... Adding Venasaur to the Pokedex\n");
    add_pokemon(pokedex, venasaur);
    assert(count_total_pokemon(pokedex) == 3);

    printf("    ... Adding Mew to the Pokedex\n");
    add_pokemon(pokedex, mew);

    printf("    ... Adding Mewtwo to the Pokedex\n");
    add_pokemon(pokedex, mewtwo);
    assert(count_total_pokemon(pokedex) == 5);

    printf("    ... Adding Dratini to the Pokedex\n");
    add_pokemon(pokedex, dratini);

    printf("    ... Adding Dragonair to the Pokedex\n");
    add_pokemon(pokedex, dragonair);

    printf("    ... Adding Dragonite to the Pokedex\n");
    add_pokemon(pokedex, dragonite);

    printf("    ... Finding every Pokémon.\n");
    int i = 0;
    while (i < 8) {
        find_current_pokemon(pokedex);
        next_pokemon(pokedex);
        i++;
    }

    printf("    ... Chaining together evolutions.\n");
    int i = 1;
    while (i < 100) {
        add_pokemon_evolution(pokedex, i, i+1);
        i++;
    }

    printf("    ... Creating a Pokédex of found Pokémon.\n");
    Pokedex foundDex = get_found_pokemon(pokedex);

    printf("    ... Checking that all Pokémon do not have evolutions.\n");
    int i = 0;
    while (i < 8) {
        assert(get_next_evolution(foundDex) == DOES_NOT_EVOLVE);
        next_pokemon(foundDex);
        i++;
    }

    printf("    ... Destroying the Pokédex of found Pokémon.\n");
    destroy_pokedex(foundDex);

    printf("    ... Destroying the original Pokedex.\n");
    destroy_pokedex(pokedex);

    printf("\n>> Passed SubDex evolution testing!\n");

}
//test if the removal of pokemon in new dex, keeps the same pokemon in original
//pokedex to ensure that copies are made in the new dex.
static void test_subdex_removal(void) {

    printf("\n>> Testing SubDex removal.\n");

    printf("    ... Creating a new original Pokédex.\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur\n");
    Pokemon bulbasaur = create_bulbasaur();

    printf("    ... Creating Ivysaur\n");
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Creating Venasaur\n");
    Pokemon venasaur = create_venasaur();

    printf("    ... Creating Mew\n");
    Pokemon mew = create_mew();

    printf("    ... Creating Mewtwo\n");
    Pokemon mewtwo = create_mewtwo();

    printf("    ... Creating Dratini\n");
    Pokemon dratini = create_dratini();

    printf("    ... Creating Dragonair\n");
    Pokemon dragonair = create_dragonair();

    printf("    ... Creating Dragonite\n");
    Pokemon dragonite = create_dragonite();

    printf("    ... Creating Pikachu\n");
    Pokemon pikachu = create_pikachu();

    printf("    ... Adding Bulbasaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    assert(count_total_pokemon(pokedex) == 1);

    printf("    ... Adding Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, ivysaur);
    assert(count_total_pokemon(pokedex) == 2);

    printf("    ... Adding Venasaur to the Pokedex\n");
    add_pokemon(pokedex, venasaur);
    assert(count_total_pokemon(pokedex) == 3);

    printf("    ... Adding Mew to the Pokedex\n");
    add_pokemon(pokedex, mew);

    printf("    ... Adding Mewtwo to the Pokedex\n");
    add_pokemon(pokedex, mewtwo);
    assert(count_total_pokemon(pokedex) == 5);

    printf("    ... Adding Dratini to the Pokedex\n");
    add_pokemon(pokedex, dratini);

    printf("    ... Adding Dragonair to the Pokedex\n");
    add_pokemon(pokedex, dragonair);

    printf("    ... Adding Dragonite to the Pokedex\n");
    add_pokemon(pokedex, dragonite);

    printf("    ... Finding every other Pokémon.\n");
    int i = 0;
    while (i < 8) {
        if (i%2 != 0) {
            find_current_pokemon(pokedex);
        }
        next_pokemon(pokedex);
        i++;
    }

    printf("    ... Creating a new Pokédex from found Pokémon.\n");
    Pokedex found_dex = get_found_pokemon(pokedex);

    printf("    ... Removing every odd Pokémon in this SubDex.\n");
    int i = 0;
    while (i < 4) {
        if (i%2 != 0) {
            remove_pokemon(found_dex);
        }
        next_pokemon(found_dex);
        i++;
    }

    printf("    ... Ensuring the No. of Pokémon in the SubDex is 25.\n");
    assert(count_total_pokemon(found_dex) == 2);

    printf("    ... and that the No. of Pokémon in original Pokédex is 100.\n");
    assert(count_total_pokemon(pokedex) == 8);

    printf("    ... Destroying the SubDex.\n");
    destroy_pokedex(found_dex);

    printf("    ... Destroying the Pokedex.\n");
    destroy_pokedex(pokedex);

    printf(">> Passed SubDex removal testing!\n");

}


////////////////////////////////////////////////////////////////////////
//                     Helper Functions                               //
////////////////////////////////////////////////////////////////////////

// Helper function to create Bulbasaur for testing purposes.
static Pokemon create_bulbasaur(void) {
    Pokemon pokemon = new_pokemon(
            BULBASAUR_ID, BULBASAUR_NAME,
            BULBASAUR_HEIGHT, BULBASAUR_WEIGHT,
            BULBASAUR_FIRST_TYPE,
            BULBASAUR_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Ivysaur for testing purposes.
static Pokemon create_ivysaur(void) {
    Pokemon pokemon = new_pokemon(
            IVYSAUR_ID, IVYSAUR_NAME,
            IVYSAUR_HEIGHT, IVYSAUR_WEIGHT,
            IVYSAUR_FIRST_TYPE,
            IVYSAUR_SECOND_TYPE
    );
    return pokemon;
}
// Helper function to create Venasaur for testing purposes.
static Pokemon create_venasaur(void){
    Pokemon pokemon = new_pokemon(
        VENASAUR_ID, VENASAUR_NAME,
        VENASAUR_HEIGHT, VENASAUR_WEIGHT,
        VENASAUR_FIRST_TYPE,
        VENASAUR_SECOND_TYPE
    );
    return pokemon;
}
// Helper function to create Mew for testing purposes.
static Pokemon create_mew(void){
    Pokemon pokemon = new_pokemon(
            MEW_ID, MEW_NAME,
            MEW_HEIGHT, MEW_WEIGHT,
            MEW_FIRST_TYPE,
            MEW_SECOND_TYPE
    );
    return pokemon;
}
// Helper function to create Mewtwo for testing purposes.
static Pokemon create_mewtwo(void){
    Pokemon pokemon = new_pokemon(
            MEWTWO_ID, MEWTWO_NAME,
            MEWTWO_HEIGHT, MEWTWO_WEIGHT,
            MEWTWO_FIRST_TYPE,
            MEWTWO_SECOND_TYPE
    );
    return pokemon;
}

static Pokemon create_dratini(void){
    Pokemon pokemon = new_pokemon(
            DRATINI_ID, DRATINI_NAME,
            DRATINI_HEIGHT, DRATINI_WEIGHT,
            DRATINI_FIRST_TYPE,
            DRATINI_SECOND_TYPE
    );
    return pokemon;
}

static Pokemon create_dragonair(void){
    Pokemon pokemon = new_pokemon(
            DRAGONAIR_ID, DRAGONAIR_NAME,
            DRAGONAIR_HEIGHT, DRAGONAIR_WEIGHT,
            DRAGONAIR_FIRST_TYPE,
            DRAGONAIR_SECOND_TYPE
    );
    return pokemon;
}

static Pokemon create_dragonite(void){
    Pokemon pokemon = new_pokemon(
            DRAGONITE_ID, DRAGONITE_NAME,
            DRAGONITE_HEIGHT, DRAGONITE_WEIGHT,
            DRAGONITE_FIRST_TYPE,
            DRAGONITE_SECOND_TYPE
    );
    return pokemon;
}

static Pokemon create_pikachu(void){
    Pokemon pokemon = new_pokemon(
            PIKACHU_ID, PIKACHU_NAME,
            PIKACHU_HEIGHT, PIKACHU_WEIGHT,
            PIKACHU_FIRST_TYPE,
            PIKACHU_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to compare whether two Pokemon are the same.
// This checks that the two pointers contain the same address, i.e.
// they are both pointing to the same pokemon struct in memory.
//
// Pokemon ivysaur = new_pokemon(0, 'ivysaur', 1.0, 13.0, GRASS_TYPE, POISON_TYPE)
// Pokemon also_ivysaur = ivysaur
// is_same_pokemon(ivysaur, also_ivysaur) == TRUE
static int is_same_pokemon(Pokemon first, Pokemon second) {
    return first == second;
}

// Helper function to compare whether one Pokemon is a *copy* of
// another, based on whether their attributes match (e.g. pokemon_id,
// height, weight, etc).
// 
// It also checks that the pointers do *not* match -- i.e. that the
// pointers aren't both pointing to the same pokemon struct in memory.
// If the pointers both contain the same address, then the second
// Pokemon is not a *copy* of the first Pokemon.
// 
// This function doesn't (yet) check that the Pokemon's names match
// (but perhaps you could add that check yourself...).
static int is_copied_pokemon(Pokemon first, Pokemon second) {
    return (pokemon_id(first) == pokemon_id(second))
    &&  (first != second)
    &&  (pokemon_height(first) == pokemon_height(second))
    &&  (pokemon_weight(first) == pokemon_weight(second))
    &&  (pokemon_first_type(first) == pokemon_first_type(second))
    &&  (pokemon_second_type(first) == pokemon_second_type(second));
}
//Checks the current pokemon is the pokemon given and checks that pokemon is 
//not NULL
static void run_current_check(Pokedex pokedex, Pokemon pokemon) {
    if (pokemon != NULL) {
        printf("       --> Checking %s is selected\n", pokemon_name(pokemon));
        assert(is_same_pokemon(get_current_pokemon(pokedex), pokemon));
    }
    return;
}