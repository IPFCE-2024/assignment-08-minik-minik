#include "include/exercise4.h"
#include <assert.h>

/* Initialize an empty stack */
void initialize(stack *s) {
    s->head = NULL;
}

/* Push an element onto the stack */
void push(stack *s, int e) {
    node *new_node = (node*)malloc(sizeof(node));
    if (new_node != NULL) {
        new_node->data = e;
        new_node->next = s->head;
        s->head = new_node;
    }
}

/* Pop an element from the stack */
int pop(stack *s) {
    if (empty(s)) {
        return -1;  // Error case
    }
    node *temp = s->head;
    int data = temp->data;
    s->head = s->head->next;
    free(temp);
    return data;
}

/* Check if stack is empty */
bool empty(stack *s) {
    return s->head == NULL;
}

/* Check if stack is full (always false for linked list) */
bool full(stack *s) {
    return false;
}

void init_queue(queue *q) {

    assert(q != NULL); // Ensure queue is not empty

    // Initialize queue stacks with functions allowed
    initialize(&(q->s1));
    initialize(&(q->s2));
}

void enqueue(queue *q, int x) {

    assert(q != NULL); // Ensure queue is not empty

    push(&q->s1, x); // Push x to s1
}

int dequeue(queue *q) {

    assert(q != NULL); // Ensure queue is not empty

    // If s2 is empty: move data from s1 to s2
    if(empty(&q->s2)){
        while(!empty(&q->s1)){
            // Push and pop x from s1 to s2 until s1 is empty
            int x = pop(&q->s1);
            push(&q->s2, x);
        }
    }
    return pop(&q->s2); // Return front element
}

bool queue_empty(queue *q) {
    assert(q != NULL); // Ensure queue is not empty
    return empty(&q->s1) && empty(&q->s2); // Check if queue is empty via function
}

bool queue_full(queue *q) {
    return false; // "Never" full
}

/* Helper function to print the queue */
void print_queue(queue *q) {
    /* Note: This function needs to access the structure for display purposes
     * In a real implementation, you might not have this function,
     * or you'd implement it using only the queue operations
     */
    printf("Queue contents: ");
    
    // Temporary stacks to preserve queue state
    stack temp1, temp2;
    initialize(&temp1);
    initialize(&temp2);
    
    // Copy s2 to temp (s2 has elements in dequeue order)
    while (!empty(&q->s2)) {
        int val = pop(&q->s2);
        push(&temp1, val);
    }
    
    // Copy s1 to temp (s1 has elements in reverse order)
    while (!empty(&q->s1)) {
        int val = pop(&q->s1);
        push(&temp2, val);
    }
    
    // Print temp1 (these will be dequeued first)
    while (!empty(&temp1)) {
        int val = pop(&temp1);
        printf("%d ", val);
        push(&q->s2, val);  // Restore
    }
    
    // Print temp2 in reverse (these will be dequeued last)
    while (!empty(&temp2)) {
        int val = pop(&temp2);
        push(&temp1, val);
    }
    while (!empty(&temp1)) {
        int val = pop(&temp1);
        printf("%d ", val);
        push(&q->s1, val);  // Restore
    }
    
    printf("\n");
}

