#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover input.wav\n");
        return 1;
    }

    FILE *raw_file = fopen(argv[1], "r");
    FILE *out_file = NULL;

    if (raw_file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    BYTE buffer[BLOCK_SIZE];
    int count = 0;
    char filename[8];
    int is_ok = 1;

    while (is_ok)
    {
        int size = fread(buffer, sizeof(BYTE), BLOCK_SIZE, raw_file);

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (count == 0)
            {
                sprintf(filename, "%03i.jpg", count);
                out_file = fopen(filename, "w");
                fwrite(buffer, sizeof(BYTE), size, out_file);
                count++;
            }
            else
            {
                fclose(out_file);
                sprintf(filename, "%03i.jpg", count);
                out_file = fopen(filename, "w");
                fwrite(buffer, sizeof(BYTE), size, out_file);
                count++;
            }
        }
        else if (count != 0)
        {
            fwrite(buffer, sizeof(BYTE), size, out_file);
            if (size == 0)
            {
                is_ok = 0;
            }
        }
    }
    fclose(out_file);
    fclose(raw_file);
}