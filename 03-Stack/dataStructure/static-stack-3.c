#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int capacity;
    int top;
    int * arr;

    // IMPROVEMENT:
    // Could make this generic by using void* instead of int*
    // and storing element size.
} Stack;

// Acts like a constructor
Stack * CreateStack(int capacity)
{
    // IMPROVEMENT:
    // Validate capacity (e.g., capacity > 0)

    Stack * s = (Stack*)malloc(sizeof(Stack));
    // IMPROVEMENT:
    // Check if malloc returned NULL before using 's'

    s->capacity = capacity;
    s->top = -1;

    s->arr = (int*)malloc(sizeof(int) * capacity);
    // IMPROVEMENT:
    // Check if malloc for array failed; free 's' if it does

    return s;

    // IMPROVEMENT:
    // Avoid casting malloc in C (not required)
}

// Creating a push function
void Push(Stack * s , int value)
{
    // IMPROVEMENT:
    // Check if 's' is NULL before using it

    if(s->top == s->capacity - 1)
    {
        printf("Maximum Capacity of %d Reached \n", s->capacity);
        printf("Stack Overflow !!! \n");
        return;

        // IMPROVEMENT:
        // Instead of printing, return a status code (e.g., int)
    }
    
    s->top++;
    s->arr[s->top] = value;
    
    printf("Pushed %d into the Stack \n" , value);

    // IMPROVEMENT:
    // Separate logic from I/O (avoid printing inside data structure functions)
}

// Creating Pop Function
void Pop(Stack * s)
{
    // IMPROVEMENT:
    // Check if 's' is NULL

    if(s->top == -1)
    {
        printf("Stack Underflow !!! \n");
        return;

        // IMPROVEMENT:
        // Return an error code or value instead of printing
    }
    
    printf("Popped %d from the Stack \n" , s->arr[s->top]);
    s->top--;

    // IMPROVEMENT:
    // Better to return the popped value
}

// Peek function
void Peek(Stack * s)
{
    // IMPROVEMENT:
    // Check if 's' is NULL

    if(s->top == -1)
    {
        printf("Stack Empty !!! \n");
        return;

        // IMPROVEMENT:
        // Return a value instead of printing
    }
    
    printf("%d at the top of the Stack \n" , s->arr[s->top]);
}

// Dump entire stack
void DumpStack(Stack * s)
{
    // IMPROVEMENT:
    // Check if 's' is NULL

    if(s->top == -1)
    {
        printf("Stack Empty !!! \n");
        return;
    }
    
    int * arr = s->arr; // pointer to the head of array

    int max = s->capacity;
    // IMPROVEMENT:
    // This prints full capacity, including unused elements.
    // Should ideally print only up to 'top'.

    for(int i = 0 ; i < max ; i++)
    {
        printf("index %d value %d \n" , i , arr[i]);
    }
}

// IMPROVEMENT:
// Add a FreeStack() function to release allocated memory
// to avoid memory leaks.

int main()
{
    Stack * stack1 = CreateStack(3);

    // IMPROVEMENT:
    // Check if CreateStack returned NULL before using stack1

    Peek(stack1);
    Push(stack1 , 1);
    Peek(stack1);
    Pop(stack1);
    Peek(stack1);
    Push(stack1 , 1);
    Push(stack1 , 2);
    Push(stack1 , 3);
    Push(stack1 , 4);
    DumpStack(stack1);

    // IMPROVEMENT:
    // Free allocated memory using FreeStack(stack1)

    return 0;
}