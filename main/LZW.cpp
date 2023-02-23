#include "LZW.h"

void LZW::compress(std::istream& in, std::ostream& out)
{
    std::unordered_map<std::string, int> dictionary;
    for (int i = 0; i < 256; i++) {
        dictionary[std::string(1, (char)i)] = i;
    }
    int next_code = 256;

    std::string current = "";
    char c;
    while (in.get(c)) {
        std::string next = current + c;
        if (dictionary.count(next)) {
            current = next;
        } else {
            out.write((char*)&dictionary[current], sizeof(int));
            dictionary[next] = next_code++;
            current = std::string(1, c);
        }
    }
    if (!current.empty()) {
        out.write((char*)&dictionary[current], sizeof(int));
    }
}

void LZW::decompress(std::istream& in, std::ostream& out)
{
    std::vector<std::string> dictionary;
    for (int i = 0; i < 256; i++) {
        dictionary.push_back(std::string(1, (char)i));
    }
    int next_code = 256;

    int code;
    while (in.read((char*)&code, sizeof(int))) {
        if (code < dictionary.size()) {
            out << dictionary[code];
        } else {
            out << dictionary[code - 1] << dictionary[code - 1][0];
        }
        if (next_code < 4096) {
            dictionary.push_back(dictionary[code] + dictionary[code][0]);
            next_code++;
        }
    }
}
