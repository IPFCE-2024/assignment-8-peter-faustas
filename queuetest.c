#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "queue.h"
#include "queue.c"

int main() {
    
    queue q;

    initialize(&q);
    //test 1 - Efter at execute init_queue(q); the queue q must be empty.
    assert(empty(&q) == true);
    printf("Succes\n");

    //test 2 - Efter execute af enqueue(q,x); y = dequeue(q); skal køen være det samme som før, og x og y skal være det samme.
    int x;
    enqueue(&q,x);
    int y = dequeue(&q);
    assert(y==x);
    assert(empty(&q) == true);
    printf("Succes\n");

    //test 3 - Efter execute af fire commands skal q være det samme før de 4 commands. x0 skal være 0 y0 og x1 skal være lig y1
    int x0;
    int x1;
    int y0;
    int y1;
    enqueue(&q,x0);
    enqueue(&q,x1);
    y0 = dequeue(&q);
    y1 = dequeue(&q);
    assert(x0==y0);
    assert(y1==x1);
    assert(empty(&q) == true);
    printf("Succes\n");
}