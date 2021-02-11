//
// Created by karabag on 22.01.2021.
//
#include <stdio.h>
#include <unistd.h>
#include "multilevelFeedbackQueue.h"


void createAndAddProcess(struct Queue *queue) {

    //I created burst time array for creating process
    int processBurstArray[20] = {7, 27, 44, 32, 31, 28, 16, 8, 23, 49, 8, 11, 9, 27, 21, 38, 42, 50, 4, 19};

    for (int i = 0; i < 20; i++) {
        //I created process
        struct Process process = {i + 1, processBurstArray[i], "NEW."};
        printf("%s %d %s %d %s %s %s", "Process", process.pid, "created with a burst time of", process.burstTime,
               "ms. Its state is assigned to", process.state, "\n");
        enqueue(queue, process);
    }
}

void roundRobinQ8(struct Queue *queue1, struct Queue *queue2) {

    int quantumTime = 8;
    struct Node *temp = queue1->head;
    //print ready process in queue
    printf("\n\n");
    while (temp != NULL) {
        temp->process.state = "READY.";
        printf("%s %d %s %d %s %s %s", "Process", temp->process.pid, "moved to 1st RR Queue with a burst time of",
               temp->process.burstTime, "ms. Its state is updated to", temp->process.state, "\n");
        temp = temp->next;
    }
    printf("\n\n");
    struct Node *temp2 = queue1->head;

    while (temp2 != NULL) {
        //print running process in queue
        temp2->process.state = "RUNNING.";
        printf("%s %d %s %d %s %s %s", "Process", temp2->process.pid, "moved from 1st RR Queue to CPU with a burst time of",
               temp2->process.burstTime, "ms. Its state is updated to", temp2->process.state, "\n");
        if (temp2->process.burstTime > quantumTime) {
            temp2->process.burstTime -= quantumTime;
            usleep(quantumTime*1000);
            temp2->process.state = "BLOCKED.";
            printf("%s %d %s %d %s %s %s", "Process", temp2->process.pid, "removed from CPU with a remaining burst time of",
                   temp2->process.burstTime, "ms. Its state is updated to", temp2->process.state, "\n");

            enqueue(queue2, dequeue(queue1)->process);
        } else {
            usleep(temp2->process.burstTime*1000);
            temp2->process.state = "TERMINATED.";
            //Process 1 removed from CPU for completing its execution. Its state is updated to TERMINATED.
            printf("%s %d %s %s %s", "Process", temp2->process.pid,
                   "removed from CPU for completing its execution. Its state is updated to", temp2->process.state,
                   "\n");
            dequeue(queue1);
        }

        temp2 = temp2->next;
    }
}

void roundRobinQ16(struct Queue *queue1, struct Queue *queue2) {
    int quantumTime = 16;
    struct Node *temp = queue1->head;
    printf("\n\n");
    while (temp != NULL) {
        temp->process.state = "READY.";
        printf("%s %d %s %d %s %s %s", "Process", temp->process.pid, "moved to 2nd RR Queue with a remaining burst time of",
               temp->process.burstTime, "ms. Its state is updated to", temp->process.state, "\n");
        temp = temp->next;
    }
    printf("\n\n");
    struct Node *temp2 = queue1->head;

    while (temp2 != NULL) {
        //print running process in queue
        temp2->process.state = "RUNNING.";
        printf("%s %d %s %d %s %s %s", "Process", temp2->process.pid, "moved to 2nd RR Queue to CPU with a burst time of",
               temp2->process.burstTime, "ms. Its state is updated to", temp2->process.state, "\n");
        if (temp2->process.burstTime > quantumTime) {
            usleep(quantumTime*1000);
            temp2->process.burstTime -= quantumTime;
            temp2->process.state = "BLOCKED.";
            printf("%s %d %s %d %s %s %s", "Process", temp2->process.pid, "removed from CPU with a remaining burst time of",
                   temp2->process.burstTime, "ms. Its state is updated to", temp2->process.state, "\n");
            enqueue(queue2, dequeue(queue1)->process);
        } else {
            usleep(temp2->process.burstTime*1000);
            temp2->process.state = "TERMINATED.";
            printf("%s %d %s %s %s", "Process", temp2->process.pid,
                   "removed from CPU for completing its execution. Its state is updated to", temp2->process.state,
                   "\n");
            dequeue(queue1);
        }

        temp2 = temp2->next;
    }
    printf("\n\n");

}

void fCfS(struct Queue *queue) {
    struct Node *temp = queue->head;
    while (temp != NULL) {
        temp->process.state = "READY.";
        printf("%s %d %s %d %s %s %s", "Process", temp->process.pid, "moved to FCFS Queue with a burst time of",
               temp->process.burstTime, "ms. Its state is updated to", temp->process.state, "\n");
        temp = temp->next;
    }
    printf("\n\n");
    struct Node *temp2 = queue->head;
    while (temp2 != NULL) {
        temp2->process.state = "RUNNING.";
        printf("%s %d %s %d %s %s %s", "Process", temp2->process.pid, "moved from FCFS Queue to CPU with a burst time of",
               temp2->process.burstTime, "ms. Its state is updated to", temp2->process.state, "\n");
        usleep(temp2->process.burstTime*1000);
        temp2->process.state = "TERMINATED.";
        printf("%s %d %s %s %s", "Process", temp2->process.pid,
               "removed from CPU for completing its execution. Its state is updated to", temp2->process.state, "\n");
        dequeue(queue);
        temp2 = temp2->next;
    }


}


