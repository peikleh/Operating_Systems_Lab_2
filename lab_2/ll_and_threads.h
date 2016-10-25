/* 
 * File:   ll_and_threads.h
 * Author: nevin
 *
 * Created on October 12, 2016, 1:39 PM
 */

#ifndef LL_AND_THREADS_H
#define	LL_AND_THREADS_H
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <random>
#include <unistd.h>
/*####################keeps everything in one file.
#############################################
 * Linked List Functions
#################################################################*/

typedef struct node{
    int contents;
    struct node *next;
    struct node *prev;
} Node;

typedef struct L_list{
    Node* head;
    pthread_mutex_t mutex;

 }L_list;

L_list* create_list(int contents);
void add_to_end(int contents, L_list* list);
void delete_node(L_list* list, Node* node);
void print(Node* node);
int size_list( L_list *list);
void* producer_1(void *arg);
void* producer_2(void *arg);
void* consumer_2(void *arg);
void* consumer_1(void *arg);

























#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* LL_AND_THREADS_H */

