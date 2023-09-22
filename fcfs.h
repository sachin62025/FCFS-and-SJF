
struct Process {
    char name[20];
    int arrival_time;
    int burst_time;
};
void FCFS(struct Process processes[], int n);
