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
    while (true)
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < height; j++)
            {
                if (height - i > j + 1)
                {
                    printf(" ");
                }
                else
                {
                    printf("#");
                }
            }
            printf("\n");
        }
        break;
    }
    /*
    while(true){
        for(int i = 0; i < count; i++){
            printf("#");
        }
        printf("\n");
        count++;
        height--;
        if(height == 0){
            break;
        }
    }*/
}