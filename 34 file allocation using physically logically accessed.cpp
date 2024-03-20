#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_DATA_LENGTH 50

struct Record {
    char data[MAX_DATA_LENGTH];
};

struct File {
    struct Record records[MAX_RECORDS];
    int current_position;
};

void initializeFile(struct File *file) {
    file->current_position = 0;
}

void addRecord(struct File *file, const char *data) {
    if (file->current_position < MAX_RECORDS) {
        strcpy(file->records[file->current_position].data, data);
        file->current_position++;
        printf("Record added successfully.\n");
    } else {
        printf("File is full. Cannot add more records.\n");
    }
}

void printRecords(struct File *file) {
    printf("Records in the file:\n");
    for (int i = 0; i < file->current_position; i++) {
        printf("Record %d: %s\n", i + 1, file->records[i].data);
    }
}

int main() {
    struct File file;
    initializeFile(&file);

    // Adding some sample records
    addRecord(&file, "First record");
    addRecord(&file, "Second record");
    addRecord(&file, "Third record");

    // Printing all records
    printRecords(&file);

    return 0;
}

