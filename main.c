//Emre Karabağ 210201053
#include <stdio.h>
#include "multilevelFeedbackQueue.h"


int main() {
    printf("%s", "Simulation Started!\n\n");
    struct Queue *roundRobin8 = QueueInit();
    struct Queue *roundRobin16 = QueueInit();
    struct Queue *firstComeFirstServe = QueueInit();

    createAndAddProcess(roundRobin8);
    roundRobinQ8(roundRobin8, roundRobin16);
    roundRobinQ16(roundRobin16, firstComeFirstServe);
    fCfS(firstComeFirstServe);
    printf("\nSimulation Completed...");

}

