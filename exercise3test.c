#include "include/exercise3.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

int main(){

    queue q;
    
    initialize(&q);

    if(empty(&q)){
        printf("Queue initialization successfull. Queue is empty\n");
    } else{
        printf("Queue initialization unsuccessfull.\n");
    }

    int x = 25;
    int y = 13;

    enqueue(&q, x);

    y = dequeue(&q);

    if(empty(&q) && x == y){
        printf("Enqueue and dequeue operations successful.\n");
    } else{
        printf("Enqueue and dequeue operations unsuccessful.\n");
    }

    int x0 = 57;
    int x1 = 9;

    int y0 = 90;
    int y1 = 78;

    enqueue(&q, x0);
    enqueue(&q, x1);

    y0 = dequeue(&q);
    y1 = dequeue(&q);

    if(empty(&q) && y0 == x0 && y1 == x1){
        printf("Test sequence successful.\n");
    } else{
        printf("Test sequence unsuccessful.\n");
    }
    return 0;
}