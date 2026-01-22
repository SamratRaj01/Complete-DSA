#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printInBetween(int * arr , int start , int end)
{

    printf("Set %d : \n" , start + 1);

    for(int i = start ; i <= end ; i++)
    {
        printf("%d " , arr[i]);
    }

    printf("\n");
}

void extractWindow(int * arr , int start , int windowSize , int * windowArr)
{
    for(int i = 0 ; i < windowSize ; i++)
    {
        windowArr[i] = arr[start + i];
    }
}

bool isArrMatch(int * arr1 , int arr1Size , int * arr2 , int arr2Size)
{
    for(int i = 0 ; i < arr1Size ; i++)
    {
        int found = 0;
        for(int j = 0 ; j < arr2Size ; j++)
        {
            if(arr1[i] == arr2[j])
            {
                found = 1;
                break;
            }
        }
        if(!found)
            return false;
    }
    return true;
}

void SlideTheWindow(int * arr, int arrSize ,int windowSize)
{
    if(windowSize > arrSize)
    {
        printf("window cannot be greater than array size");
        return;
    }
    
    int start = 0;
    int end = start + windowSize - 1;

    for(int i = 0 ; i <= arrSize - windowSize ; i++)
    {
        printInBetween(arr , start , end);
        
        start++;
        end++;
    }
}

void SlideAndCompare(int * arr, int arrSize ,int windowSize, int * subarr, int subarrSize)
{
    if(windowSize > arrSize)
    {
        printf("window cannot be greater than array size");
        return;
    }
    
    int start = 0;
    int end = start + windowSize - 1;

    for(int i = 0 ; i <= arrSize - windowSize ; i++)
    {
        int windowArr[windowSize];
        extractWindow(arr , start , windowSize , windowArr);
        
        if(isArrMatch(windowArr, windowSize, subarr, subarrSize))
        {
            printf("Match found!\n");
        }
        
        start++;
        end++;
    }
}


int main()
{
    int arr[] = {1,2,3,4,5};
    int subarr[] = {1,2,3};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    int subarrSize = sizeof(subarr)/sizeof(subarr[0]);
    int windowSize = 3;

    printf("\n--- Basic Sliding Window ---\n");
    SlideTheWindow(arr , arrSize , windowSize);
    
    printf("\n--- Sliding Window with Comparison ---\n");
    SlideAndCompare(arr , arrSize , windowSize, subarr, subarrSize);

    return 0;
}