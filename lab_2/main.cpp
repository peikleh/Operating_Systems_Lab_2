
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

L_list* create_list(int contents) {
    Node* start = (Node*) malloc(sizeof (Node));
    start->contents = contents;
    start->prev = NULL;
    start->next = NULL;
    L_list* l_list = (L_list*) malloc(sizeof(L_list));
    l_list->head = start;
    return l_list;
}


void add_to_end(int contents, L_list *list) {
    Node* new_node = (Node*) malloc(sizeof (Node));
    Node* temp = list->head;
    new_node->contents = contents;
    new_node->next = NULL;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = new_node;
    new_node->prev = temp;
}

void delete_node(L_list* list, Node* node){
    
            
    if(list->head == NULL || node == NULL){
        return;
    }
    
    if(list->head == node){
        list->head = node->next;
        list->head->prev = NULL;
        
    }else if(node->next == NULL){
        
        node->prev-> next = NULL;
    }else{
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }
    
    

    free(node);
    
    
}

void print(Node *node){
    Node* temp = node;
    while (temp != NULL){
        printf("%d ", temp->contents);
        temp = temp->next;
    }
    printf("\n");
    
}

int main(int argc, char** argv) {
    L_list* list = create_list(5);
    add_to_end(10, list);
    add_to_end(15, list);

    print(list->head);
    delete_node(list, list->head->next);
    print(list->head);
    add_to_end(5, list);
    print(list->head);
     
    delete_node(list, list->head->next->next);
    print(list->head);
}


