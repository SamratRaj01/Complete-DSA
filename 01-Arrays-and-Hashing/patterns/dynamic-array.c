#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} DynamicArray;

DynamicArray* createArray(int initialCapacity)
{
    DynamicArray *arr = malloc(sizeof(DynamicArray));
    arr->data = malloc(initialCapacity * sizeof(int));
    arr->size = 0;
    arr->capacity = initialCapacity;
    return arr;
}

void resizeArray(DynamicArray *arr , int newCapacity)
{
    int *newData = realloc(arr->data, newCapacity * sizeof(int));
    
    if(newData == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    arr->data = newData;
    arr->capacity = newCapacity;        
}

void append(DynamicArray *arr , int value)
{
    if(arr->size == arr->capacity) {
        resizeArray(arr, arr->capacity * 2);
    }
    arr->data[arr->size++] = value;
}

void pop(DynamicArray *arr)
{
    if(arr->size == 0) {
        printf("Array is empty\n");
        return;
    }
    arr->size--;
    
    //shirnk when the array is <= 25% full
    if(arr->size > 0 && arr->size == arr->capacity / 4) {
        resizeArray(arr, arr->capacity / 2);
    }
}

void freeArray(DynamicArray *arr)
{
    free(arr->data);
    free(arr);
}

int main()
{
    DynamicArray *arr = createArray(2);
    
    append(arr, 10);
    append(arr, 20);
    append(arr, 30); //triggers resize

    for(int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    
    printf("\n");
    
    printf("Array size: %zu, capacity: %zu\n", arr->size, arr->capacity);
    
    pop(arr);

    
    

    printf("Array size after pop: %zu, capacity: %zu\n", arr->size, arr->capacity);

    for(int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }

    printf("\n");

    freeArray(arr);
    return 0;
}