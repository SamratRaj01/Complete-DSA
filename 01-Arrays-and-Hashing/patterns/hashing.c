#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "hashing.h"

#define TABLE_SIZE 100

unsigned int hash(char *key)
{
    unsigned long int value = 0;
    unsigned int key_length = strlen(key);

    // Do several rounds of multiplication
    for (size_t i = 0; i < key_length; i++)
    {
        // Using a prime number to reduce collisions
        // and improve distribution
        value = value * 37 + key[i];
    }

    // making sure the value is within the table size
    value = value % TABLE_SIZE;

    return value;
}

int main(void)
{
    char *key;
    key = "hello";
    printf("Hash value for '%s': %u\n", key, hash(key));
    printf("char: %c, ASCII: %d\n", key[0], key[0]);
    return 0;
}