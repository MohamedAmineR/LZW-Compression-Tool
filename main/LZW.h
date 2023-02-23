#ifndef LZW_H
#define LZW_H

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <cstring>
#include <system_error>

class LZW {
public:
    static void compress(std::istream& in, std::ostream& out);
    static void decompress(std::istream& in, std::ostream& out);
};

#endif //LZW_H
