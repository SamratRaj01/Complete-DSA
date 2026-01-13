#include <stdio.h>
#include <stdlib.h>

//swaps the value of the pointer;
void swap(int * a , int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//reversing an array
void reverseArray(int * arr , int sizeOfArr)
{

    int * left = arr;
    int * right = arr + (sizeOfArr - 1);

    while(left < right)
    {
        swap(left , right);

        left++;
        right--;
    }
}

//prints all the array element
void printArr(int * arr , int sizeOfArr)
{
    for(int i = 0 ; i < sizeOfArr ; i++)
    {
        printf("%d " , arr[i]);
    }
    printf("\n");
}

int main(void)
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};

    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Array before reversing \n");
    printArr(arr , size);

    reverseArray(arr , size);

    printf("Array after reversing \n");
    printArr(arr , size);

    return 0;
}