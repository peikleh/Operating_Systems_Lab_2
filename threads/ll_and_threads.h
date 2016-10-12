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
/*#################################################################
Function declarations. Should be in a header file but doing it here
keeps everything in one file.
#################################################################*/
typedef struct linked_list{
    int contents;
    struct linked_list *next;
    struct linked_list *prev;
} List;

List* create_list(int contents);
void add_to_end(int contents, List *list);
























#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* LL_AND_THREADS_H */

