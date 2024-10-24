#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

// Opgave 3
void initialize(queue *q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

bool empty(const queue *q) {
    return q->size <= 0;
}

bool full(const queue *q) {
    return false;
}

void enqueue(queue *q, int x) {
    node *n = (node*)malloc(sizeof(node));
    
    n->data = x;
    n->next = NULL;

    if(empty(q)){
        q->front = n;
        q->rear = n;
    }
    else{
        q->rear->next = n;
        q->rear = n;
    }
    q->size++;
}

int dequeue(queue *q) {
    if (empty(q))
    {
        return -1;
    }
    
    int result = q->front->data;

    node *temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;
    
    q->size--;
    return result;
}

// Opgave 4

void push(int element, node **head) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = element;
    newNode->next = *head;
    *head = newNode;
}

int pop(node **head) {
    if(*head == NULL){
        printf("Stack is empty\n");
        return -1;
    }
    node* temp = *head;
    int poppedValue = temp->data;
    *head = (*head)->next;
    free(temp);
    return poppedValue;
}

void enqueueStack(queue *q, int x) {
    push(x, &q->rear);
    q->size++;
}

int dequeueStack(queue *q) {
    if (q->size == NULL){
        printf("Queue is empty\n");
        return -1;
    }
    if (q->front == NULL){
        while (q->rear != NULL){
            int popped_value = pop(&(q->rear));
            push(popped_value, &(q->front));
        }
    }
    
    int dequeued_value = pop(&(q->front));

    if (dequeued_value != -1){
        q->size--;
    }

    return dequeued_value;
}

