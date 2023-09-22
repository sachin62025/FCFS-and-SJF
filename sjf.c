
// Function to perform counting sort based on burst time

#include "sjf.h" 
#include <stdio.h>
#include <stdlib.h>



void countingSort(struct Process processes[], int n) {
    struct Process temp[n];
    int max_burst_time = 0;

    for (int i = 0; i < n; i++) {
        if (processes[i].burst_time > max_burst_time) {
            max_burst_time = processes[i].burst_time;
        }
    }
     int count[20] ={0};
  //   for(int i=0;i<20;i++){
  //   count[i]=0;}
  //  count[max_burst_time + 1] = { 0 };

    for (int i = 0; i < n; i++) {
        count[processes[i].burst_time]++;
    }

    for (int i = 1; i <= max_burst_time; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        temp[count[processes[i].burst_time] - 1] = processes[i];
        count[processes[i].burst_time]--;
    }

    for (int i = 0; i < n; i++) {
        processes[i] = temp[i];
    }
}

// Function to calculate waiting time and turn-around time for SJF
void SJF(struct Process processes[], int n) {
    countingSort(processes, n);

    int waiting_time[n], turn_around_time[n];
    waiting_time[0] = 0;
    turn_around_time[0] = processes[0].burst_time;

    for (int i = 1; i < n; i++) {
        waiting_time[i] = turn_around_time[i - 1];
        turn_around_time[i] = waiting_time[i] + processes[i].burst_time;
    }

    // Calculate average waiting time and average turn-around time
    float avg_waiting_time = 0, avg_turn_around_time = 0;
    for (int i = 0; i < n; i++) {
        avg_waiting_time += waiting_time[i];
        avg_turn_around_time += turn_around_time[i];
    }
    avg_waiting_time /= n;
    avg_turn_around_time /= n;

    // Print results
    printf("SJF Scheduling:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %s - Waiting Time: %d, Turn-around Time: %d\n", processes[i].name, waiting_time[i], turn_around_time[i]);
    }
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turn-around Time: %.2f\n", avg_turn_around_time);
}
