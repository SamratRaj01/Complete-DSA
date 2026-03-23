#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int capacity;
    int top;
    int * arr;
    // int arr[capacity];
    // The above line causes a compile-time error inside a struct because
    // struct members must have a fixed size known at compile time.
    // 'capacity' is not a compile-time constant, so the compiler
    // cannot determine the size of the struct.
} Stack;

//Acts like a constructor
//Returns a stack pointer
Stack * CreateStack(int capacity)
{
    Stack * s = (Stack*)malloc(sizeof(Stack));
    s->capacity = capacity;
    s->top = -1;
    s->arr = (int*)malloc(sizeof(int) * capacity);
    return s;
}

//Push in the stack
void Push(Stack * s , int value)
{
    if(s->top == s->capacity - 1)
    {
        printf("Maximum Capacity of %d Reached \n", s->capacity);
        printf("Stack Overflow !!! \n");
        return;
    }
    
    s->top++;
    s->arr[s->top] = value;
    
    printf("Pushed %d into the Stack \n" , value);
}

//Pop from the stack
void Pop(Stack * s)
{
    if(s->top == -1)
    {
        printf("Stack Underflow !!! \n");
        return;
    }
    
    printf("Popped %d from the Stack \n" , s->arr[s->top]);
    s->top--;
    
}

//Peek at the top of the stack
void Peek(Stack * s)
{
    if(s->top == -1)
    {
        printf("Stack Empty !!! \n");
        return;
    }
    
    printf("%d at the top of the Stack \n" , s->arr[s->top]);
}

//Print all the values of the stack
void DumpStack(Stack * s)
{
    if(s->top == -1)
    {
        printf("Stack Empty !!! \n");
        return;
    }
    
    int * arr = s->arr; //pointer to the head of array
    int max = s->capacity;
    for(int i = 0 ; i < max ; i++)
    {
        printf("index %d value %d \n" , i , arr[i]);
    }
}

int main()
{
    Stack * stack1 = CreateStack(3);
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
    Pop(stack1);
    Pop(stack1);
    Pop(stack1);
    Pop(stack1);
}
