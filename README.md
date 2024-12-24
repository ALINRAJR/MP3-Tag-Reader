# MP3-Tag-Reader
Overview
The MP3 Tag Reader is a simple program written in C that extracts and displays metadata from an MP3 file's ID3v1 tags. ID3v1 tags store information such as the title, artist, album, year, comment, and genre, which are commonly used for organizing and displaying audio files.

Features
-Reads ID3v1 metadata from MP3 files.
-Displays the following information:
-Title
-Artist
-Album
-Year
-Comment
-Genre (numeric representation)
-Provides error handling for missing or invalid tags.
-Usage
-Compile the program using a C compiler (e.g., gcc):



gcc -o mp3_tag_reader mp3_tag_reader.c
Run the program with an MP3 file as input:


./mp3_tag_reader <filename>
The output will display the metadata if an ID3v1 tag is found, or notify if the tag is absent.


./mp3_tag_reader example.mp3
Output:

Title: Example Song
Artist: Example Artist
Album: Example Album
Year: 2024
Comment: Example Comment
Genre: 17

Prerequisites
A C compiler (e.g., GCC)
MP3 files with ID3v1 tags for testing

How It Works
File Handling: The program opens the specified MP3 file in binary mode.
Seek Metadata: It moves to the last 128 bytes of the file where ID3v1 tags are located.
Parse Fields: It verifies the "TAG" identifier and extracts metadata fields such as title, artist, album, etc.
Display Results: Outputs the extracted metadata to the console.

Limitations
Supports only ID3v1 tags.
Genre is displayed as a numeric value. Conversion to text can be implemented later.
Does not support extended metadata or ID3v2 tags.

Future Enhancements
Add support for ID3v2 tags.
Include genre name mapping instead of numeric representation.
Provide options to edit metadata.
