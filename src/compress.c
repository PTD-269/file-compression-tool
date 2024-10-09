#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <compress.h>

char convert_digit_to_char(int num)
{
    return 48 + num; // Simplified conversion
}
char* compress(const char* s)
{
    if (s == NULL || *s == '\0') {
        return NULL; // Handle empty or NULL input
    }

    unsigned long s_length = strlen(s);
    char* compressed_s = (char*)malloc(s_length * 2 + 1); // Ensure enough space for compression

    if (!compressed_s) {
        perror("Memory allocation failed");
        return NULL;
    }

    unsigned long i = 0, j = 0, flag = 0; // Initialize j and flag
    char pivot_character = s[0]; // Start with the first character

    while (s[i] != '\0') {
        if (pivot_character != s[i] || flag == 9) {
            compressed_s[j++] = pivot_character; // Store the character
            compressed_s[j++] = convert_digit_to_char(flag); // Store the count
            flag = 1; // Reset flag for the new character
            pivot_character = s[i]; // Update pivot character
        } else {
            flag++; // Increment the count
        }
        i++;
    }
    // Handle the last character and its count
    compressed_s[j++] = pivot_character;
    compressed_s[j++] = convert_digit_to_char(flag);
    compressed_s[j] = '\0'; // Ensure null termination

    return compressed_s;
}
char* convert_string_to_binary_string(char* s)
{
    const int NUM_OF_BITS = 8; 
    unsigned long length_s = strlen(s);
    unsigned long length_bin_s = length_s * NUM_OF_BITS;
    
    char* bin_str = (char*)malloc(length_bin_s + 1);
    
    for (int i = 0; i < length_s; i++)
    {
        char* c_in_bin_s; 
        c_in_bin_s = convert_character_to_binary_string(s[i]);
        int bound = i * 8;
        for (int j = 0; j < 8; j++)
        {
            bin_str[bound + j] = c_in_bin_s[j];
        }   
        
    }
    bin_str[length_bin_s] = '\0';
    
    return bin_str;
}

char* convert_character_to_binary_string(char c) {
    char* binary = (char*)malloc(9); // 8 bits + null terminator
    binary[8] = '\0'; // Null-terminate the string

    for (int i = 7; i >= 0; i--) {
        binary[i] = (c & 1) ? '1' : '0'; // Check the least significant bit
        c >>= 1; // Right shift to process the next bit
    }

    return binary;
}