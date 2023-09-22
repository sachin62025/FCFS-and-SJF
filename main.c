#include <stdio.h>
#include <stdlib.h>
#include "fcfs.h"
#include "sjf.h"
int main() {
    int n = 10; // Change this to 10 for 10 processes 
    struct Process processes[] = {
        {"Chrome", 0, 6},
        {"Xorg  ", 0, 8},
        {"Bash  ", 0, 7},
        {"Gedit ", 0, 3},
        {"album ", 0, 9},
        {"brave ", 0, 8},
        {"notes ", 0, 7},
        {"word  ", 0, 1},
        {"fiverr", 0, 4},
        {"Gedit ", 0, 10}
    };
    FCFS(processes, n);
    SJF(processes, n);
    return 0;
}
