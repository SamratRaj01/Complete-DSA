#include <stdio.h>
#include <stdlib.h>

void printInBetween(int * arr , int start , int end)
{

    printf("Set %d : \n" , start + 1);

    for(int i = start ; i <= end ; i++)
    {
        printf("%d " , arr[i]);
    }

    printf("\n");
}

void SlideTheWindow(int * arr, int arrSize ,int windowSize)
{
    if(windowSize > arrSize)
    {
        printf("window cannot be greater than array size");
        return;
    }
    
    int start = 0;



    for(int i = 0 ; i <= arrSize - windowSize ; i++)
    {
        int end = start + windowSize - 1;

        printInBetween(arr , start , end);

        start++;
    }

}


int main()
{
    int arr[] = {1,2,3,4,5};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    int windowSize = 2;

    SlideTheWindow(arr , arrSize , windowSize);

    return 0;
}