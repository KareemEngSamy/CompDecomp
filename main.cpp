#include "CompDec.h"
#include <iostream>
using namespace std;

int main() {
    try {
        // File paths
        string input_file = "input.txt";
        string compressed_file = "compressed.txt";
        string decompressed_file = "decompressed.txt";

        // 1. Read input text
        cout << "\nReading input file '" << input_file << "'\n";
        string text = CompDec::read_file(input_file);
        cout << "Original Text: " << text << "\n";

        // 2. Compress text
        cout << "Compressing text..." << endl;
        vector<int> compressed = CompDec::compress(text);
        string compressed_str = CompDec::compressed_data_to_string(compressed);
        cout << "Compressed Data: " << compressed_str << "\n";

        // 3. Save compressed data to file
        CompDec::write_file(compressed_file, compressed_str);
        cout << "Compressed data saved to '" << compressed_file << "'\n\n";

        // 4. Read compressed data back
        string loaded_compressed_str = CompDec::read_file(compressed_file);
        vector<int> loaded_compressed = CompDec::string_to_compressed_data(loaded_compressed_str);

        // 5. Decompress data
        cout << "Decompressing..." << endl;
        string decompressed = CompDec::decompress(loaded_compressed);
        cout << "Decompressed Text: " << decompressed;

        // 6. Save decompressed text
        CompDec::write_file(decompressed_file, decompressed);
        cout << "Decompressed text saved to '" << decompressed_file << "'\n\n";

        // 7. Verify correctness
        if (text == decompressed) {
            cout << "Success: Decompressed text matches original!\n\n";
        } else {
            cout << "Error: Decompressed text does NOT match original!\n\n";
        }
    } 
    catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }
    return 0;
}
