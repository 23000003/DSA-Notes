#include <stdio.h>
#include <stdlib.h>

void writeToFile(const char *filename) {
    FILE *file = fopen(filename, "w+");
    if (file == NULL) {
        perror("Error opening file for writing");
        return;
    }

    // Write data to the file
    fprintf(file, "Hello, World!\n");
    fprintf(file, "This is a test file.\n");

    // Move the file pointer back to the beginning for reading
    rewind(file);

    // Read the data back
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("Read from w+: %s", buffer);
    }

    fclose(file);
}

void readAndAppendToFile(const char *filename) {
    FILE *file = fopen(filename, "a+");
    if (file == NULL) {
        perror("Error opening file for appending");
        return;
    }

    // Append data to the file
    fprintf(file, "Appending new line.\n");

    // Move the file pointer to the beginning for reading
    rewind(file);

    // Read the data back
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("Read from a+: %s", buffer);
    }

    fclose(file);
}

void readAndWriteInFile(const char *filename) {
    FILE *file = fopen(filename, "r+");
    if (file == NULL) {
        perror("Error opening file for reading and writing");
        return;
    }

    // Read and modify data
    char buffer[100];
    if (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("Original: %s", buffer);
        
        // Move pointer to the start to overwrite the first line
        fseek(file, 0, SEEK_SET);
        fprintf(file, "Modified first line.\n");
    }

    // Move the pointer back to the beginning for reading
    rewind(file);

    // Read the modified data back
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("Read from r+: %s", buffer);
    }

    fclose(file);
}

int main() {
    const char *filename = "example.txt";

    // Write to file using w+
    writeToFile(filename);

    // Read and append using a+
    readAndAppendToFile(filename);

    // Read and write using r+
    readAndWriteInFile(filename);

    return 0;
}
