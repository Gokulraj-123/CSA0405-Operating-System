#include<stdio.h>

struct Process {
    int pid;
    int burst_time;
    int arrival_time;
    int priority;
    int remaining_time;
};

void swap(struct Process *xp, struct Process *yp) {
    struct Process temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort_by_priority(struct Process arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (arr[j].priority > arr[j+1].priority)
                swap(&arr[j], &arr[j+1]);
}

void priority_scheduling(struct Process processes[], int n) {
    int total_time = 0;
    int i, j;
    int done = 0;
    int current_process = -1;
    while (done < n) {
        sort_by_priority(processes, n);
        for (i = 0; i < n; i++) {
            if (processes[i].arrival_time <= total_time && processes[i].remaining_time > 0) {
                current_process = i;
                break;
            }
        }
        if (current_process == -1) {
            printf("No process available at time %d\n", total_time);
            total_time++;
            continue;
        }
        processes[current_process].remaining_time--;
        if (processes[current_process].remaining_time == 0) {
            printf("Process %d completed at time %d\n", processes[current_process].pid, total_time+1);
            done++;
        }
        total_time++;
        current_process = -1;
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process processes[n];
    for (int i = 0; i < n; i++) {
        printf("Enter details for process %d:\n", i+1);
        processes[i].pid = i+1;
        printf("Burst Time: ");
        scanf("%d", &processes[i].burst_time);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Priority: ");
        scanf("%d", &processes[i].priority);
        processes[i].remaining_time = processes[i].burst_time;
    }
    printf("\nPre-emptive Priority Scheduling:\n");
    priority_scheduling(processes, n);
    return 0;
}

