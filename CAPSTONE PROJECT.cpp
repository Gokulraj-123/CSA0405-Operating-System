#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_FILE_CONTENT_LENGTH 1000

void createFile();
void deleteFile();
void readFile();
void writeFile();
void listFiles();
void exitProgram();

int main() {
    int choice;

    do {
        printf("\nFile System Management\n");
        printf("1. Create a file\n");
        printf("2. Delete a file\n");
        printf("3. Read a file\n");
        printf("4. Write to a file\n");
        printf("5. List files\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createFile();
                break;
            case 2:
                deleteFile();
                break;
            case 3:
                readFile();
                break;
            case 4:
                writeFile();
                break;
            case 5:
                listFiles();
                break;
            case 6:
                exitProgram();
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}

void createFile() {
    char filename[MAX_FILENAME_LENGTH];
    FILE *file;

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to create the file.\n");
        return;
    }

    fclose(file);
    printf("File '%s' created successfully.\n", filename);
}

void deleteFile() {
    char filename[MAX_FILENAME_LENGTH];

    printf("Enter the filename to delete: ");
    scanf("%s", filename);

    if (remove(filename) == 0)
        printf("File '%s' deleted successfully.\n", filename);
    else
        printf("Failed to delete the file.\n");
}

void readFile() {
    char filename[MAX_FILENAME_LENGTH];
    char content[MAX_FILE_CONTENT_LENGTH];
    FILE *file;
    int c;

    printf("Enter the filename to read: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    printf("File content:\n");
    while ((c = getc(file)) != EOF)
        putchar(c);

    fclose(file);
}

void writeFile() {
    char filename[MAX_FILENAME_LENGTH];
    char content[MAX_FILE_CONTENT_LENGTH];
    FILE *file;

    printf("Enter the filename to write: ");
    scanf("%s", filename);

    printf("Enter the content: ");
    scanf(" %[^\n]s", content);

    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    fprintf(file, "%s", content);
    fclose(file);
    printf("Content written to file '%s' successfully.\n", filename);
}

void listFiles() {
    system("ls");
}

void exitProgram() {
    printf("Exiting the program.\n");
    exit(0);
}

