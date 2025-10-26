
#include "include/exercise3.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

void initialize(queue *q) {

    assert(q != NULL); // Ensure queue exists

    // Initialize empty queue
    q->front = NULL;
    q->rear = NULL;
    q->count = 0;

}

void enqueue(queue *q, int x) {

    node* new_node = malloc(sizeof(node)); // Memory allocation for new node with x as data value

    assert(new_node != NULL); // Ensure memory allocation was successful

    // Initialize new node with x as data value
    new_node->data = x;
    new_node->next = NULL;

    if(q->rear != NULL){
        q->rear->next = new_node; // Link old rear to new node
    }
    q->rear = new_node; // New node is new rear
    if(q->front == NULL) {
        q->front = new_node; // If front is empty, new node is new front
    }
    q->count++; // Count increases
}

int dequeue(queue *q) {

    assert(q->front != NULL); // Ensure front of queue is not empty

    node* temp = q->front; // Placeholder for front node
    int data = q->front->data; // Dequeue value is stored

    q->front = q->front->next; // New front becomes node before old front
    free(temp); // Free memory of old front node

    // If front is NULL then queue must be empty
    if(q->front == NULL){
        q->rear = NULL;
    } 

    q->count--; // Count decreases

    return data; // Return dequeue value
}

bool empty(const queue *q) {
    return (q->front == NULL && q->rear == NULL && q->count == 0); // Conditions for empty queue
}

bool full(const queue *q) {
    return false; // Linked list queue is "never" full
}

/* Helper function to print the queue */
void print_queue(const queue *q) {
    printf("Queue (front to rear): ");
    node *current = q->front;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" <- ");
        }
        current = current->next;
    }
    printf("\n");
}