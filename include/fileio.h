#ifndef FILEIO_H
#define FILEIO_H

char* convert_file_to_string(const char* filename);
unsigned long get_length_file(const char* filename);
void write_string_to_file(char* filename, char* s);

#endif // FILEIO_H