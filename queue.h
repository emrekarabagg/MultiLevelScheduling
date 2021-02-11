//
// Created by karabag on 14.01.2021.
//

#ifndef OS_HW5_QUEUE_H
#define OS_HW5_QUEUE_H

#include "process.h"
#define SIZE 5

struct Node {
   struct Process process;
    struct Node* next;
};

struct Queue {
    struct Node *head, *tail;
};



void enqueue(struct Queue *queue, struct Process process);
struct Node* dequeue(struct Queue *queue);
struct Queue *QueueInit();

#endif //OS_HW5_QUEUE_H
