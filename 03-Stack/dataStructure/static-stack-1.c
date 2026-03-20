//Basic Stack Data Structure Implementation With Array
#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int value)
{
    if(top == MAX - 1)
    {
        printf("Stack overflow !!! \n");
        return;
    }
        
    top++;
    stack[top] = value;
    printf("%d pushed at top of the stack \n" , value);
}

void pop()
{
    if(top == -1)
    {
        printf("No value to pop !!! \n");
        return;
    }
    
    printf("%d popped from the stack \n" , stack[top]);
    top--;
}

void display()
{
    if(top == -1)
    {
        printf("Stack Empty \n");
        return;
    }
    
    
    for(int i = 0 ; i <= top ; i++)
    {
        printf("%d value at %d position \n" , stack[i] , i);
    }
}

int main(void) {
    push(5);
    push(2);
    push(1);
    display();
    pop();
    display();
}

//Improvement 
//Make a instance based static stack 
