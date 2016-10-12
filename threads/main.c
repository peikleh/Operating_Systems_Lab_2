/* 
 * File:   main.c
 * Author: nevin
 *
 * Created on October 12, 2016, 1:37 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "ll_and_threads.h"
/*#######################
Linked List Funtions
#######################*/

List* create_list(int contents){
    List *start = malloc(sizeof(List));
    start->contents = contents;
    start->prev = NULL;
    start->next = NULL;
    return start;
}

void add_to_end(int contents, List *list){
    List *new_node = malloc(sizeof(List));
    new_node->contents = contents;
    new_node->next = NULL;
    
    
}

List *head = NULL;
List *tail = NULL;

int main(int argc, char** argv) {
    head = create_list(5);
    tail = head;
    printf("%d\n", head->contents);
    return (EXIT_SUCCESS);
}

