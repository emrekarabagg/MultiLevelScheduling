//
// Created by karabag on 14.01.2021.
//
#include <stdlib.h>
#include "queue.h"
#include "process.h"

struct Queue *QueueInit() {
    struct Queue *thisQueue = malloc(sizeof *thisQueue);
    thisQueue->head = NULL;
    thisQueue->tail = NULL;
    return thisQueue;
}

void enqueue(struct Queue *queue, struct Process process) {
    struct Node *temp;
    temp = malloc(sizeof(struct Node));
    temp->process = process;
    temp->next = NULL;
    if(queue->head == NULL && queue->tail == NULL) { //empty
        queue->head = queue->tail = temp;
        return;
    }
    queue->tail->next = temp;
    queue->tail = temp;
}

struct Node* dequeue(struct Queue *queue) {
    struct Node* temp = queue->head;
    if(queue->head == NULL) return NULL;   //empty
    if(queue->head == queue->tail) {
        queue->head = queue->tail = NULL;
    }
    else {
        queue->head = queue->head->next;
    }
    return temp;
}