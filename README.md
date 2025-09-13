# 📦 CompDec – LZW Compression & Decompression in C++

This project demonstrates a **complete implementation of the LZW (Lempel–Ziv–Welch) compression algorithm** with file I/O support.  
It can:
- Compress text into integer codes
- Save/load compressed data from files
- Decompress codes back into the original text
- Verify correctness by comparing original and decompressed text



## 🧠 Theory – How LZW Works
LZW is a **dictionary-based compression algorithm** widely used in GIF and TIFF formats.  
It works as follows:

1. **Initialize Dictionary**  
   - Start with a dictionary of all single characters (ASCII 0–255).

2. **Compression Process**  
   - Read characters and build the **longest sequence** already in the dictionary.  
   - Output the dictionary code for that sequence.  
   - Add the sequence + next character as a new entry to the dictionary.  

  
3. **Decompression Process**  
   - Use the codes to reconstruct text.  
   - If a code isn’t in the dictionary yet, build it using the previous sequence + first character.  
   - Add new entries while decoding.


## ⚙️ Build & Run
```
g++ main.cpp CompDec.cpp -o compdec
./compdec
```

## 🧪 Example Output
```
Reading input file 'input.txt'
Original Text: TOBEORNOTTOBEORTOBEORNOT

Compressing text...
Compressed Data: 84 79 66 69 79 82 78 79 84 256 258 260 
Compressed data saved to 'compressed.txt'

Decompressing...
Decompressed Text: TOBEORNOTTOBEORTOBEORNOT
Decompressed text saved to 'decompressed.txt'

Success: Decompressed text matches original!
```

## 🎯 Why This Project Matters

- Demonstrates the **LZW compression algorithm**, a widely studied and practical technique in data compression.  
- Provides a **clear C++ implementation** including file I/O, dictionary-based encoding, and decoding.  
- Shows a **complete compression–decompression workflow**: read → compress → save → load → decompress → verify.  
- Serves as a **foundation for extensions**, such as binary storage, Unicode support, and performance optimizations.  

## 🚀 Possible Improvements
- **Binary storage**: Save codes in binary instead of text for real size reduction.  
- **Unicode support**: Extend dictionary beyond ASCII to handle UTF-8/UTF-16.  
- **Dictionary reset**: Prevent unbounded growth by resetting or limiting size.  
- **Compression ratio**: Display effectiveness (`compressed_size / original_size`).  
- **Streaming**: Process large files in chunks instead of loading all at once.  

## 📚 References

- [Wikipedia – Lempel–Ziv–Welch (LZW)](https://en.wikipedia.org/wiki/Lempel–Ziv–Welch)  
- [GeeksforGeeks – LZW (Lempel Ziv Welch) Compression technique](https://www.geeksforgeeks.org/lzw-lempel-ziv-welch-compression-technique/)   




