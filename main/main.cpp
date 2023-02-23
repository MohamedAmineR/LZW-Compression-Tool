#include <iostream>
#include <fstream>
#include "LZW.h"

int main()
{
    // compress a file
    std::ifstream input_file("input.txt", std::ios::binary);
    std::ofstream compressed_file("compressed.bin", std::ios::binary);
    if (!input_file || !compressed_file) {
        std::cerr << "Failed to open file." << std::endl;
        return 1;
    }
    LZW::compress(input_file, compressed_file);
    input_file.close();
    compressed_file.close();

    // decompress the compressed file
    std::ifstream compressed_input_file("compressed.bin", std::ios::binary);
    std::ofstream decompressed_file("decompressed.txt", std::ios::binary);
    if (!compressed_input_file || !decompressed_file) {
        std::cerr << "Failed to open file." << std::endl;
        return 1;
    }
    LZW::decompress(compressed_input_file, decompressed_file);
    compressed_input_file.close();
    decompressed_file.close();

    return 0;
}
