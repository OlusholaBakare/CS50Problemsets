#include <stdio.h>
#include <stdlib.h>
 
int main(int argc, char *argv[]){
    if (argc != 2){
        printf("Usage: %s memoryName\n",argv[0]);
        return 1;
    }

    #include <stdio.h>

    // Open the memory card file for reading
    FILE *cardFile = fopen("card.raw", "rb");

    if (cardFile == NULL)
    {
        printf("Could not open card file.\n");
        return 1;
    }

    FILE *jpegFile = NULL;
    unsigned char buffer[512];

    while (fread(buffer, sizeof(char), 512, cardFile) == 512)
    {
        // Check if it's the start of a new JPEG file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff)
        {
            // Close the previous JPEG file if one is open
            if (jpegFile != NULL)
            {
                fclose(jpegFile);
            }

            // Create a new JPEG file
            int fileCount = 1;
            char filename[8];
            sprintf(filename, "%03i.jpg", fileCount++);
            jpegFile = fopen(filename, "wb");
        }

        // Write the block to the JPEG file if one is open
        if (jpegFile != NULL)
        {
            fwrite(buffer, sizeof(char), 512, jpegFile);
        }
    }

    // Close any open files
    if (jpegFile != NULL)
    {
        fclose(jpegFile);
    }

    fclose(cardFile);

    return 0;
}

