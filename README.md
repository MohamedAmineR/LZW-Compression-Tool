# LZW-Compression-Tool
Program Overview
The LZW compression program is a command-line tool that compresses input files using the Lempel-Ziv-Welch (LZW) algorithm. The program takes an input file, compresses it using the LZW algorithm, and outputs the compressed data to a new file. The compressed file can be decompressed back to the original file using a separate decompression program.

Program Structure
The program consists of the following components:

Input module: reads input files and converts them to a sequence of symbols.
Compression module: compresses the input sequence using the LZW algorithm.
Output module: writes the compressed data to an output file.
Input File Format
The input file format is a text file containing ASCII-encoded characters. The file may contain any combination of printable ASCII characters (0x20 to 0x7E), including spaces, tabs, and newlines.

Output File Format
The output file format is a binary file containing the compressed data. The compressed data consists of a sequence of variable-length codes representing substrings from the input sequence. The codes are encoded as 12-bit integers and are stored in little-endian byte order.

User Interface
The program is run from the command line with the following syntax:


lzw-compress <input-file> <output-file>

Where <input-file> is the path to the input file and <output-file> is the path to the output file.

Upon running the program, the user will see a status message indicating the progress of the compression process. The program will then exit with a status code indicating success or failure.

Conclusion
This is a basic outline of the LZW compression program, including its structure, input and output file formats, and user interface. More detailed design specifications, implementation details, and error handling may be needed to create a complete and robust program.
