#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA_LENGTH 50

struct Block {
    char data[MAX_DATA_LENGTH];
    struct Block *next;
};

void addBlock(struct Block **first, struct Block **last, const char *data) {
    struct Block *new_block = (struct Block *)malloc(sizeof(struct Block));
    if (new_block == NULL) {
        printf("Memory allocation failed. Cannot add block.\n");
        return;
    }
    strcpy(new_block->data, data);
    new_block->next = NULL;

    if (*first == NULL) {
        *first = new_block;
    } else {
        (*last)->next = new_block;
    }
    *last = new_block;
}

void printFileContents(struct Block *first) {
    printf("File contents:\n");
    struct Block *current_block = first;
    while (current_block != NULL) {
        printf("%s\n", current_block->data);
        current_block = current_block->next;
    }
}

void freeFile(struct Block **first) {
    struct Block *current_block = *first;
    while (current_block != NULL) {
        struct Block *temp = current_block;
        current_block = current_block->next;
        free(temp);
    }
    *first = NULL;
}

int main() {
    struct Block *first_block = NULL;
    struct Block *last_block = NULL;

    // Adding some sample blocks
    addBlock(&first_block, &last_block, "First block");
    addBlock(&first_block, &last_block, "Second block");
    addBlock(&first_block, &last_block, "Third block");

    // Printing file contents
    printFileContents(first_block);

    // Freeing memory
    freeFile(&first_block);

    return 0;
}

