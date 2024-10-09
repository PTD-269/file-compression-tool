#include <stdio.h>
#include <stdlib.h>
#include "compress.h"
#include "fileio.h"

int main() {
    const char *filename = "samples/sample1.txt"; // Ensure this file exists
    char* s = convert_file_to_string(filename);
    const char* compresed_filename = "bin_compressed/sample1.rle";
    const char* decompresed_filename = "bin_decompressed/sample1.rle";
    
    char* compressed_s;
    compressed_s = compress(s);

    char* compressed_bin_s;
    compressed_bin_s = convert_string_to_binary_string(compressed_s);
    
    write_string_to_file(compresed_filename, compressed_bin_s);
    
    free(s); // Free allocated memory
    free(compressed_s); // Free allocated memory
    return 0;
}