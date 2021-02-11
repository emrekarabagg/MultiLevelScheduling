//
// Created by karabag on 22.01.2021.
//

#ifndef OS_HW5_MULTILEVELFEEDBACKQUEUE_H
#define OS_HW5_MULTILEVELFEEDBACKQUEUE_H

#include "queue.h"
#include "process.h"

void createAndAddProcess(struct Queue *queue);

void roundRobinQ8(struct Queue *queue1, struct Queue *queue2);

void roundRobinQ16(struct Queue *queue1, struct Queue *queue2);

void fCfS(struct Queue *queue);


#endif //OS_HW5_MULTILEVELFEEDBACKQUEUE_H
