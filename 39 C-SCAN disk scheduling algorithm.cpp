#include <stdio.h>
#include <stdlib.h>

void cscan(int requests[], int total_requests, int current_head_position, int direction) {
    int total_movement = 0;
    int max_cylinder = 199; // Maximum cylinder number in this simulation
    printf("Sequence of head movement:\n%d", current_head_position);

    if (direction == 1) { // Moving towards higher cylinder numbers
        for (int i = current_head_position; i <= max_cylinder; i++) {
            if (requests[i] == 1) {
                total_movement += abs(current_head_position - i);
                printf(" -> %d", i);
                current_head_position = i;
                requests[i] = 0; // Mark the request as serviced
            }
        }
        for (int i = 0; i < current_head_position; i++) {
            if (requests[i] == 1) {
                total_movement += abs(current_head_position - i);
                printf(" -> %d", i);
                current_head_position = i;
                requests[i] = 0; // Mark the request as serviced
            }
        }
    } else { // Moving towards lower cylinder numbers
        for (int i = current_head_position; i >= 0; i--) {
            if (requests[i] == 1) {
                total_movement += abs(current_head_position - i);
                printf(" -> %d", i);
                current_head_position = i;
                requests[i] = 0; // Mark the request as serviced
            }
        }
        for (int i = max_cylinder; i > current_head_position; i--) {
            if (requests[i] == 1) {
                total_movement += abs(current_head_position - i);
                printf(" -> %d", i);
                current_head_position = i;
                requests[i] = 0; // Mark the request as serviced
            }
        }
    }

    printf("\nTotal head movement: %d\n", total_movement);
}

int main() {
    int requests[200] = {0}; // Assuming max 200 cylinders
    int total_requests, current_head_position, direction;

    printf("Enter the total number of disk requests: ");
    scanf("%d", &total_requests);

    printf("Enter the current head position: ");
    scanf("%d", &current_head_position);

    printf("Enter the direction (1 for towards higher cylinder numbers, 0 for towards lower cylinder numbers): ");
    scanf("%d", &direction);

    printf("Enter the disk requests:\n");
    for (int i = 0; i < total_requests; i++) {
        int request;
        scanf("%d", &request);
        requests[request] = 1; // Marking requested cylinders
    }

    cscan(requests, 200, current_head_position, direction);
    return 0;
}

