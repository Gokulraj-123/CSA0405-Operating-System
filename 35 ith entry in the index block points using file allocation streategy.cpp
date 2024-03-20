#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BLOCKS 100
#define MAX_DATA_LENGTH 50

struct Block {
    char data[MAX_DATA_LENGTH];
};

struct File {
    struct Block blocks[MAX_BLOCKS];
    int index_block[MAX_BLOCKS];  // Index block containing pointers to file blocks
    int total_blocks;
};

void initializeFile(struct File *file) {
    file->total_blocks = 0;
    memset(file->index_block, -1, sizeof(file->index_block)); // Initialize index block pointers to -1
}

void addBlock(struct File *file, const char *data) {
    if (file->total_blocks < MAX_BLOCKS) {
        strcpy(file->blocks[file->total_blocks].data, data);
        file->index_block[file->total_blocks] = file->total_blocks; // Point index block entry to the block
        file->total_blocks++;
        printf("Block added successfully.\n");
    } else {
        printf("File is full. Cannot add more blocks.\n");
    }
}

void printFileContents(struct File *file) {
    printf("File contents:\n");
    for (int i = 0; i < file->total_blocks; i++) {
        printf("Block %d: %s\n", i + 1, file->blocks[file->index_block[i]].data);
    }
}

int main() {
    struct File file;
    initializeFile(&file);

    // Adding some sample blocks
    addBlock(&file, "First block");
    addBlock(&file, "Second block");
    addBlock(&file, "Third block");

    // Printing file contents
    printFileContents(&file);

    return 0;
}

