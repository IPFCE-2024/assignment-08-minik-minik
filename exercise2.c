/*
 * Exercise 2: Insertion Sort for Singly Linked List
 * Assignment 8 - IPFCE 2025
 * 
 * Implement insertion sort for a singly linked list of integers.
 * The list should be sorted in-place from smallest to largest.
 * No new nodes should be allocated - only pointers should be changed.
 */

#include "include/exercise2.h"
#include <assert.h>

/* 
 * Sort a singly linked list in-place using insertion sort
 * list: pointer to the first node of the list
 * 
 * The function should sort the list by rearranging pointers,
 * not by creating new nodes or swapping data values.
 * Returns pointer to the new head of the sorted list.
 */
node* isort(node* list) {

    assert(list != NULL); // List must not be empty

    // If list contains only one element: list is sorted
    if(list->next == NULL)
        return list;

    node* sorted = NULL; // Set initial sorted list to NULL
    node* current = list; // Start at the unsorted list

    // Go through all nodes
    while(current != NULL){
        node* next = current->next; 

        // If the sorted list is empty, or if current data is smaller than the previous: insert data as first
        if(sorted == NULL || current->data < sorted->data){
            current->next = sorted; // Point to start of the sorted list
            sorted = current; // Current is now the start of the sorted list
        } else{

            // Else: search for the data's place in the sorted list
            node* search = sorted;

            // Continue through the list until sorting place is found
            while(search->next != NULL && search->next->data < current->data){
                search = search->next;
            }
            // Current continues after data place is found
            current->next = search->next;
            search->next = current;
        }
        // Continue through nodes
        current = next;
    }
    return sorted; // Return sorted list
}

/* Helper function to print the list */
void print_list(node* list) {
    node* current = list;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf(" -> NULL\n");
}

/* Helper function to create a node */
node *create_node(int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    if (!new_node)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

/* Helper function to free the list */
void free_list(node *list)
{
    node *current = list;
    node *next_node;

    while (current != NULL)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }
}
