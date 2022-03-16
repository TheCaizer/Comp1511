#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

int most_frequent(struct node *head);
struct node *strings_to_list(int len, char *strings[]);

// DO NOT CHANGE THIS MAIN FUNCTION

int main(int argc, char *argv[]) {
    // create linked list from command line arguments
    struct node *head = strings_to_list(argc - 1, &argv[1]);

    int result = most_frequent(head);
    printf("%d\n", result);

    return 0;
}


// return the value which occurs most frequently in a linked list
// if several values are equally most frequent
// the value that occurs earliest in the list is returned
int most_frequent(struct node *head) {
    struct node *curr = head;
    int answer = 0;
    int max_size = 0;
    while(curr != NULL){
        int count_size = 0;
        struct node *check = head;
        while(check != NULL){
            if(curr->data == check->data){
                count_size++;
                check = check->next;
            }
            else{
                check = check->next;
            }
        }
        if(count_size > max_size){
            max_size = count_size;
        }
        curr = curr->next;
    }
    struct node *curr1 = head;
    
    while(curr1 != NULL){
        int count = 0;
        struct node *check1 = head;
        while(check1 != NULL){
            if(curr1->data == check1->data){
                count++;
                check1 = check1->next;
            }
            else{
                check1 = check1->next;
            }
        }
        if(count == max_size){
            answer = curr1->data;
            return answer;
        }
        curr1 = curr1->next;
    }
    return answer;

}


// DO NOT CHANGE THIS FUNCTION

// create linked list from array of strings
struct node *strings_to_list(int len, char *strings[]) {
    struct node *head = NULL;
    for (int i = len - 1; i >= 0; i = i - 1) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = atoi(strings[i]);
        head = n;
    }
    return head;
}
