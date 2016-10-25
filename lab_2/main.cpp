
/* 
 * File:   main.c
 * Author: nevin
 *
 * Created on October 12, 2016, 1:37 PM
 */


#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <random>
#include <unistd.h>

/*####################keeps everything in one file.
#############################################
 * Header information
#################################################################*/

typedef struct node {
    int contents;
    struct node *next;
    struct node *prev;
} Node;

typedef struct L_list {
    Node* head;
    pthread_mutex_t mutex;

} L_list;



L_list* create_list(int contents);
void add_to_end(int contents, L_list* list);
void delete_node(L_list* list, Node* node);
void print(Node* node);
int size_list(L_list *list);
void* producer_1(void *arg);
void* producer_2(void *arg);
void* consumer_2(void *arg);
void* consumer_1(void *arg);



L_list* list = create_list(rand() % 40);
pthread_t thread[4];


/*#######################
Linked Node Funtions
#######################*/


void* producer_1(void *arg) {
    //adds an odd number to list
    int addition;
    while (true) {
        //makes output easier to deal with. Comment out if necessary
        sleep(1);
        //lock list
        pthread_mutex_lock(&list->mutex);
        printf("Producer_1: ");
        print(list->head);

        if (size_list(list) > 40) {
            printf("Producer_1: ");
            printf("Overflow!\n\n");
            //unlock list
            pthread_mutex_unlock(&list->mutex);

        } else {
            addition = ((rand() % 20) * 2) + 1;
            add_to_end(addition, list);
            printf("Producer_1: ");
            print(list->head);
            printf("\n");
            //unlock list
            pthread_mutex_unlock(&list->mutex);
        }
    }
}

void* producer_2(void *arg) {
    //adds even numbers to list
    int addition;
    while (1) {
        sleep(1);
        pthread_mutex_lock(&list->mutex);
        printf("Producer_2: ");
        print(list->head);
        if (size_list(list) > 40) {
            printf("Producer_2: ");
            printf("Overflow!\n\n");
            pthread_mutex_unlock(&list->mutex);
        } else {
            addition = ((rand() % 20) * 2);
            add_to_end(addition, list);
            printf("Producer_2: ");
            print(list->head);
            printf("\n");
            pthread_mutex_unlock(&list->mutex);
        }
    }
}

void* consumer_1(void *arg) {
    //consumes odd number from list
    while (1) {
        sleep(1);
        pthread_mutex_lock(&list->mutex);
        printf("Consumer_1: ");
        print(list->head);
        if (size_list(list) == 0) {
            printf("Consumer_1: ");
            printf("Underflow!\n\n");
            pthread_mutex_unlock(&list->mutex);
        } else {
            Node* temp = list->head;
            temp = list->head;
            while (temp != NULL && (temp->contents % 2 == 0)) {
                temp = temp->next;
            }
            if (temp != NULL) {
                delete_node(list, temp);
            }
            printf("Consumer_1: ");
            print(list->head);
            printf("\n");
            pthread_mutex_unlock(&list->mutex);
        }
    }
}

void* consumer_2(void *arg) {
    //consumes even number from list
    while (1) {
        sleep(1);
        pthread_mutex_lock(&list->mutex);
        printf("Consumer_2: ");
        print(list->head);
        if (size_list(list) == 0) {
            printf("Consumer_2: ");
            printf("Underflow!\n\n");
            pthread_mutex_unlock(&list->mutex);
        } else {
            Node* temp = list->head;
            temp = list->head;
            
            while (temp != NULL && (temp->contents % 2 != 0)) {
                temp = temp->next;
            }
            if (temp != NULL) {
                delete_node(list, temp);
            }
            printf("Consumer_2: ");
            print(list->head);
            printf("\n");
            pthread_mutex_unlock(&list->mutex);
        }
    }
}

/*#######################
Linked List Functions
#######################*/

L_list* create_list(int contents) {
    Node* start = (Node*) malloc(sizeof (Node));
    start->contents = contents;
    start->prev = NULL;
    start->next = NULL;
    L_list* l_list = (L_list*) malloc(sizeof (L_list));
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

int size_list(L_list *list) {
    Node* temp = list->head;
    int size = 0;
    while (temp != NULL) {
        temp = temp->next;
        size++;
    }
    return size;
}

void delete_node(L_list* list, Node* node) {
    if (list->head == NULL || node == NULL) {
        return;
    }

    if (list->head == node) {
        list->head = node->next;
        list->head->prev = NULL;

    } else if (node->next == NULL) {
        node->prev-> next = NULL;
    } else {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }
    free(node);
}

void print(Node *node) {
    //prints list given head node
    Node* temp = node;
    while (temp != NULL) {
        printf("%d ", temp->contents);
        temp = temp->next;
    }
    printf("\n");
}

int main(int argc, char** argv) {
    //adds two more elemets to list created globally at the top of the file
    add_to_end(rand() % 40, list);
    add_to_end(rand() % 40, list);

    //initialize mutex belonging to global list defined at top of file
    if (pthread_mutex_init(&list->mutex, NULL) != 0) {
        printf("Mutext failed\n");
    }

    //create each thread
    pthread_create(&thread[0], NULL, *producer_1, NULL);
    pthread_create(&thread[1], NULL, *producer_2, NULL);
    pthread_create(&thread[2], NULL, *consumer_1, NULL);
    pthread_create(&thread[3], NULL, *consumer_2, NULL);

    //start each thread
    pthread_join(thread[0], NULL);
    pthread_join(thread[1], NULL);
    pthread_join(thread[2], NULL);
    pthread_join(thread[3], NULL);

}


