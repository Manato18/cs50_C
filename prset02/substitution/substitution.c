#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string n);
char rotate(char s, int n);

int main(int argc, string argv[])
{
    // プログラムが1つのコマンドライン引数で実行されたことを確認する。
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // argv[1] に含まれるすべての文字が数字であることを確認する。
    if (only_digits(argv[1]))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    int n = atoi(argv[1]);

    // 平文を入力するようにユーザに促す
    string text = get_string("plaintext:  ");
    printf("ciphertext: ");

    // 平文に含まれる各文字ごとに繰り返す
    for (int i = 0; i < strlen(text); i++)
    {
        char c = rotate(text[i], n);
        printf("%c", c);
    }
    printf("\n");
    return 0;
}
bool only_digits(string num)
{
    for (int i = 0; i < 9; i++)
    {
        if (num[0] == i + 65)
        {
            return true;
        }
    }
    return false;
}
char rotate(char s, int n)
{
    int x = 0;
    for (int i = 0; i < 25; i++)
    {
        if (s == i + 65)
        {
            x += s + n;
        }
        if (x > 90)
        {
            x -= 26;
        }
    }
    for (int i = 0; i < 25; i++)
    {
        if (s == i + 97)
        {
            x += s + n;
        }
        if (x > 122)
        {
            x -= 26;
        }
    }
    if (x < 65 || (90 < x && x < 97) || 122 < x)
    {
        return s;
    }
    return x;
}