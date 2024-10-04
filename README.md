# File Compression Tool

## Description

File Compression Tool is a simple utility that compresses and decompresses text files using the Run-Length Encoding (RLE) algorithm. This project demonstrates key I/O concepts in C, including file handling and binary file operations.

## Features

- Compress text files using RLE algorithm
- Decompress RLE-compressed files back to their original form
- Display compression statistics:
  - Original file size
  - Compressed file size
  - Compression ratio

## Key I/O Concepts Covered

- File opening and closing
- Reading from files character by character
- Writing to files
- Error handling for file operations
- Working with binary files (for the compressed output)

## Project Structure

- `compress.c`: Handles the compression logic
- `decompress.c`: Handles the decompression logic
- `fileio.c` and `fileio.h`: Contains common file I/O functions
- `main.c`: Main program to handle user input and call appropriate functions