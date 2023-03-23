// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <cs50.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

static node *nnext;
int count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int index = hash(word);
    nnext = table[index] -> next;
    while (nnext != NULL)
    {
        int result = strcasecmp(nnext -> word, word);
        if (result == 0)
        {
            return true;
        }
        nnext = nnext -> next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");
    if (file = NULL)
    {
        printf("Could not open file.\n");
        return false;
    }
    for (int i = 0; i < N; i++)
    {
        node *tmp = malloc(sizeof(node));
        if (tmp == NULL)
        {
            printf("Cound not enough memory\n");
            return false;
        }
        tmp -> next = NULL;
        table[i] = tmp;
    }

    char buffer[LENGTH + 1];
    int index = 0;

    while (true)
    {
        node *tmp = malloc(sizeof(node));
        if (tmp == NULL)
        {
            printf("Cound not enough memory\n");
            return false;
        }
        if (fscanf(file, % s, buffer) == EOF)
        {
            break;
        }
        strcpy(tmp -> word, buffer);
        index = hash(tmp -> word);
        tmp -> next = table[index] -> next;
        table[index] -> next = tmp;
        count++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        nnext = table[i];
        while (nnext != NULL)
        {
            node *tmp = nnext;
            nnext = nnext-> next;
            free(tmp);
        }
    }
    return true;
}
