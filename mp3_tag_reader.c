//Alin Raj Rajagopalan Nair
//24/12/2024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ID3V1_TAG_SIZE 128
#define ID3V1_HEADER "TAG"

// Function to read ID3v1 metadata from an MP3 file
void readID3v1(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("File opening failed");
        return;
    }

    // Move to the last 128 bytes of the file
    fseek(file, -ID3V1_TAG_SIZE, SEEK_END);

    char tag[ID3V1_TAG_SIZE];
    fread(tag, 1, ID3V1_TAG_SIZE, file);
    fclose(file);

    // Check if the file contains the ID3v1 header
    if (strncmp(tag, ID3V1_HEADER, 3) != 0) {
        printf("No ID3v1 tag found in the file.\n");
        return;
    }

    // Extract metadata fields
    char title[31], artist[31], album[31], year[5], comment[31];
    int genre;

    strncpy(title, tag + 3, 30); title[30] = '\0';
    strncpy(artist, tag + 33, 30); artist[30] = '\0';
    strncpy(album, tag + 63, 30); album[30] = '\0';
    strncpy(year, tag + 93, 4); year[4] = '\0';
    strncpy(comment, tag + 97, 30); comment[30] = '\0';
    genre = tag[127];

    // Display metadata
    printf("Title: %s\n", title);
    printf("Artist: %s\n", artist);
    printf("Album: %s\n", album);
    printf("Year: %s\n", year);
    printf("Comment: %s\n", comment);
    printf("Genre: %d\n", genre);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    readID3v1(argv[1]);
    return 0;
}
