#include <stdio.h>
#include <stdlib.h>
#include <fileio.h>

unsigned long get_length_file(const char* filename)
{   
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("Failed to open file");
        return 0; // Return 0 if file cannot be opened
    }
    unsigned long count = 0;
    char c;
    while((c = fgetc(fp)) != EOF)
    {
       count++;
    }    
   
    fclose(fp);
    return count;
}

char* convert_file_to_string(const char* filename)
{
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        perror("Failed to open file");
        return NULL; // Return NULL if file cannot be opened
    }
    long file_length = get_length_file(filename);
    char* s = (char*)malloc(file_length + 1);
    if (!s) {
        fclose(fp);
        perror("Memory allocation failed");
        return NULL; // Return NULL if memory allocation fails
    }

    char c;
    unsigned long i = 0; // Initialize i

    while((c = fgetc(fp)) != EOF)
    {
       s[i] = c;
       i++;
    }    
    s[i] = '\0'; // Ensure null termination
    fclose(fp);
    return s;
}

void write_string_to_file(char* filename, char* s) 
{
    FILE* fp = fopen(filename, "w");
    if (!fp) {
        perror("Failed to write file");
        return;
    }

    fprintf(fp, s);

    fclose(fp);
}
