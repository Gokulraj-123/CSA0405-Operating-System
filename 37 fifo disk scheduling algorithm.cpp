#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 100

void fcfs(int requests[], int total_requests, int current_head_position) {
    int total_movement = 0;
    printf("Sequence of head movement:\n%d", current_head_position);
    for (int i = 0; i < total_requests; i++) {
        total_movement += abs(current_head_position - requests[i]);
        printf(" -> %d", requests[i]);
        current_head_position = requests[i];
    }
    printf("\nTotal head movement: %d\n", total_movement);
}

int main() {
    int requests[MAX_REQUESTS];
    int total_requests, current_head_position;

    printf("Enter the total number of disk requests: ");
    scanf("%d", &total_requests);

    printf("Enter the current head position: ");
    scanf("%d", &current_head_position);

    printf("Enter the disk requests:\n");
    for (int i = 0; i < total_requests; i++) {
        scanf("%d", &requests[i]);
    }

    fcfs(requests, total_requests, current_head_position);
    return 0;
}

