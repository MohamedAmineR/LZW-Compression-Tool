#include <iostream>
#include <fstream>
#include "LZW.h"

int main() {
    std::cout << "Compressing small.txt..." << std::endl;
    {
        std::ifstream in("test_files/small.txt", std::ios::binary);
        std::ofstream out("small.lzw", std::ios::binary);
        LZW::compress(in, out);
    }

    std::cout << "Decompressing small.lzw..." << std::endl;
    {
        std::ifstream in("small.lzw", std::ios::binary);
        std::ofstream out("small.out", std::ios::binary);
        LZW::decompress(in, out);
    }

    std::cout << "Comparing small.txt and small.out..." << std::endl;
    {
        std::ifstream file1("test_files/small.txt", std::ios::binary | std::ios::ate);
        std::ifstream file2("small.out", std::ios::binary | std::ios::ate);
        if (file1.tellg() != file2.tellg()) {
            std::cout << "ERROR: The decompressed file size does not match the original file size." << std::endl;
        } else {
            file1.seekg(0);
            file2.seekg(0);
            if (std::equal(std::istreambuf_iterator<char>(file1.rdbuf()),
                           std::istreambuf_iterator<char>(),
                           std::istreambuf_iterator<char>(file2.rdbuf()))) {
                std::cout << "SUCCESS: The decompressed file matches the original file." << std::endl;
            } else {
                std::cout << "ERROR: The decompressed file does not match the original file." << std::endl;
            }
        }
    }
    std::cout << "Compressing large.txt..." << std::endl;
    {
        std::ifstream in("test_files/large.txt", std::ios::binary);
        std::ofstream out("large.lzw", std::ios::binary);
        LZW::compress(in, out);
    }

    std::cout << "Decompressing large.lzw..." << std::endl;
    {
        std::ifstream in("large.lzw", std::ios::binary);
        std::ofstream out("large.out", std::ios::binary);
        LZW::decompress(in, out);
    }

    std::cout << "Comparing large.txt and large.out..." << std::endl;
    {
        std::ifstream file1("test_files/large.txt", std::ios::binary | std::ios::ate);
        std::ifstream file2("large.out", std::ios::binary | std::ios::ate);
        if (file1.tellg() != file2.tellg()) {
            std::cout << "ERROR: The decompressed file size does not match the original file size." << std::endl;
        } else {
            file1.seekg(0);
            file2.seekg(0);
            if (std::equal(std::istreambuf_iterator<char>(file1.rdbuf()),
                           std::istreambuf_iterator<char>(),
                           std::istreambuf_iterator<char>(file2.rdbuf()))) {
                std::cout << "SUCCESS: The decompressed file matches the original file." << std::endl;
            } else {
                std::cout << "ERROR: The decompressed file does not match the original file." << std::endl;
            }
        }
    }
    std::cout << "Compressing binary.bin..." << std::endl;
    {
        std::ifstream in("binary.bin", std::ios::binary);
        std::ofstream out("binary.lzw", std::ios::binary);
        LZW::compress(in, out);
    }

    std::cout << "Decompressing binary.lzw..." << std::endl;
    {
        std::ifstream in("binary.lzw", std::ios::binary);
        std::ofstream out("binary.out", std::ios::binary);
        LZW::decompress(in, out);
    }
    std::cout << "Compressing binary.bin..." << std::endl;
    {
        std::ifstream in("binary.bin", std::ios::binary);
        std::ofstream out("binary.lzw", std::ios::binary);
        LZW::compress(in, out);
    }

    std::cout << "Decompressing binary.lzw..." << std::endl;
    {
        std::ifstream in("binary.lzw", std::ios::binary);
        std::ofstream out("binary.out", std::ios::binary);
        LZW::decompress(in, out);
    }
    std::cout << "Comparing binary.bin and binary.out..." << std::endl;
    {
        std::ifstream file1("test_files/binary.bin", std::ios::binary | std::ios::ate);
        std::ifstream file2("binary.out", std::ios::binary | std::ios::ate);
        if (file1.tellg() != file2.tellg()) {
            std::cout << "ERROR: The decompressed file size does not match the original file size." << std::endl;
        } else {
            file1.seekg(0);
            file2.seekg(0);
            if (std::equal(std::istreambuf_iterator<char>(file1.rdbuf()),
                           std::istreambuf_iterator<char>(),
                           std::istreambuf_iterator<char>(file2.rdbuf()))) {
                std::cout << "SUCCESS: The decompressed file matches the original file." << std::endl;
            } else {
                std::cout << "ERROR: The decompressed file does not match the original file." << std::endl;
            }
        }
    }
    std::cout << "Testing corrupted.bin..." << std::endl;
    {
        std::ifstream in("test_files/corrupted.bin", std::ios::binary);
        std::ofstream out("corrupted.lzw", std::ios::binary);
        LZW::compress(in, out);
    }

    std::cout << "Decompressing corrupted.lzw..." << std::endl;
    {
        std::ifstream in("corrupted.lzw", std::ios::binary);
        std::ofstream out("corrupted.out", std::ios::binary);
        LZW::decompress(in, out);
    }

    std::cout << "Comparing small.txt and corrupted.out..." << std::endl;
    {
        std::ifstream file1("corrupted.txt", std::ios::binary | std::ios::ate);
        std::ifstream file2("corrupted.out", std::ios::binary | std::ios::ate);
        if (file1.tellg() != file2.tellg()) {
            std::cout << "ERROR: The decompressed file size does not match the original file size." << std::endl;
        } else {
            file1.seekg(0);
            file2.seekg(0);
            if (std::equal(std::istreambuf_iterator<char>(file1.rdbuf()),
                           std::istreambuf_iterator<char>(),
                           std::istreambuf_iterator<char>(file2.rdbuf()))) {
                std::cout << "SUCCESS: The decompressed file matches the original file." << std::endl;
            } else {
                std::cout << "ERROR: The decompressed file does not match the original file." << std::endl;
            }
        }
    }
    return 0;
}