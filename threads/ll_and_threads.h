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
/*####################keeps everything in one file.
#############################################
 * Linked List Functions
#################################################################*/
typedef struct node{
    int contents;
    struct node *next;
    struct node *prev;
} Node;

Node* create_list(int contents);
void add_to_end(int contents, Node *list);
void delete(Node *node);
























#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* LL_AND_THREADS_H */

