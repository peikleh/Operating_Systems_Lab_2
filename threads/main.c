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
Linked Node Funtions
#######################*/

Node* create_list(int contents) {
    Node *start = (Node*) malloc(sizeof (Node));
    start->contents = contents;
    start->prev = NULL;
    start->next = NULL;
    return start;
}

void delete(Node *node){
    
}
void add_to_end(int contents, Node *list) {
    Node *new_node = (Node*) malloc(sizeof (Node));
    Node *temp = list;
    new_node->contents = contents;
    new_node->next = NULL;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
}

int main(int argc, char** argv) {
    Node *head = NULL;
    head = create_list(5);
    add_to_end(10, head);

    head = head->next;

    head = head->prev;
   // printf("%d\n", head->contents);

}

