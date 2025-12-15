#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashing.h"

#define TABLE_SIZE 100

typedef struct entry {
    char *key;
    char *value;
    struct entry *next;
} entry;

typedef struct {
    entry **entries;
} HashMap; 

HashMap *createHashMap() {
    
    HashMap *hashMap = malloc(sizeof(HashMap));

    hashMap->entries = malloc(sizeof(entry*) * TABLE_SIZE);
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashMap->entries[i] = NULL;
    }
    return hashMap;
}

void dumpHashMap(HashMap *hashMap) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        entry *current = hashMap->entries[i];
        

        if(current == NULL) {
            printf("Index %d: NULL\n", i);
            continue;
        }
    
    }
}

void insert(HashMap *map, const char *key, const char *value) {
    unsigned int idx = hash((char *)key);
    entry *node = malloc(sizeof(entry));
    if (!node) return; // handle error properly
    node->key = strdup(key);        // allocates & copies
    node->value = strdup(value);    // allocates & copies
    node->next = map->entries[idx];
    map->entries[idx] = node;
}

int main(void)
{
    HashMap *hashMap = createHashMap();
    dumpHashMap(hashMap);
    return 0;
}

