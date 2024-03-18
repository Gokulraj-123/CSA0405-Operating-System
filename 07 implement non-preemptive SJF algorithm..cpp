#include <stdio.h>

struct Process {
    int pid;
    int burst_time;
    int arrival_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
};

void calculate_times(struct Process processes[], int n) {
    int total_time = 0;
    for (int i = 0; i < n; i++) {
        processes[i].waiting_time = total_time - processes[i].arrival_time;
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
        total_time += processes[i].burst_time;
        processes[i].completion_time = total_time;
    }
}

void sjf_non_preemptive(struct Process processes[], int n) {
    int shortest_job_index;
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        shortest_job_index = i;
        for (int j = i + 1; j < n; j++) {
            if (processes[j].burst_time < processes[shortest_job_index].burst_time &&
                processes[j].arrival_time <= current_time) {
                shortest_job_index = j;
            }
        }
        struct Process temp = processes[i];
        processes[i] = processes[shortest_job_index];
        processes[shortest_job_index] = temp;
        current_time += processes[i].burst_time;
    }
    calculate_times(processes, n);
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
    }
    sjf_non_preemptive(processes, n);
    printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time,
               processes[i].arrival_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
    return 0;
}

