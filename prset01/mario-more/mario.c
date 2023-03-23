#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int count = 1;
    int height;
    while (true)
    {
        height = get_int("Height: ");
        if (height > 0 && height < 9)
        {
            break;
        }
    }
    for (int i = 1; i <= height; i++)
    {
        for (int j = 0; j < height - i; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("  ");
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}