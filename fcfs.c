#include "fcfs.h" 
#include <stdio.h>
#include <stdlib.h>
void FCFS(struct Process processes[], int n) {
    int waiting_time[n], turn_around_time[n];
    waiting_time[0] = 0;
    turn_around_time[0] = processes[0].burst_time;

    for (int i = 1; i < n; i++) {
        waiting_time[i] = waiting_time[i - 1] + processes[i - 1].burst_time;
        turn_around_time[i] = waiting_time[i] + processes[i].burst_time;
    }
    float avg_waiting_time = 0, avg_turn_around_time = 0;
    for (int i = 0; i < n; i++) {
        avg_waiting_time += waiting_time[i];
        avg_turn_around_time += turn_around_time[i];
    }
    avg_waiting_time /= n;
    avg_turn_around_time /= n;
    printf("FCFS Scheduling:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %s - Waiting Time: %d, Turn-around Time: %d\n", processes[i].name, waiting_time[i], turn_around_time[i]);
    }
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turn-around Time: %.2f\n\n", avg_turn_around_time);
}
