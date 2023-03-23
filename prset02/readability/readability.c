#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string s = get_string("Text: ");

    int moji = count_letters(s);
    int count = count_words(s);
    int sentence = count_sentences(s);
    double L = (double) moji / (double)count * 100.0f;
    double S = (double) sentence / (double)count * 100.0f;

    int index = (int)roundf(0.0588 * L - 0.296 * S - 15.8);

    printf("文字%s\n", s);
    printf("文字数: %d, wordcount: %d, sentences: %d\n", moji, count, sentence);
    printf("%d\n", index);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index < 16)
    {
        printf("Grade %d\n", index);
    }
    else
    {
        printf("Grade 16+\n");
    }
}

int count_letters(string text)
{
    int moji = 0;
    int y = strlen(text);

    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (text[i] == (j + 65) || text[i] == (j + 97))
            {
                moji += 1;
            }
        }
    }
    return moji;
}
int count_words(string text)
{
    int words = 1;
    int y = strlen(text);
    for (int i = 0; i < y; i++)
    {
        if (text[i] == 32)
        {
            words++;
        }
    }
    return words;
}
int count_sentences(string text)
{
    int sentences = 0;
    int y = strlen(text);
    for (int i = 0; i < y; i++)
    {
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            sentences++;
        }
    }
    return sentences;
}