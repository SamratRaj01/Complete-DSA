#include <stdio.h>
#include <stdlib.h>


void printAll(int * head ,int length)
{
    for(int i = 0 ; i < length ; i++)
    {
        printf("%d\n",*(head+i));
    }
}

void instertAtPosition(int * head , int position , int data)
{
    *((head + position)) = data;
}

int main(void)
{
    int size = 10;
    int * arr = (int *)malloc(size * sizeof(int));

    for(int i = 0 ; i < 10 ; i++)
    {
        arr[i] = i;
    }

    printAll(arr , size);

    instertAtPosition(&arr , 5 , 100);

    printAll(arr , size);

    // printf("%d",*arr);
    // printf("%d",*(arr+1));
    // printf("%d",*arr[5]);
  
    return 0;
};