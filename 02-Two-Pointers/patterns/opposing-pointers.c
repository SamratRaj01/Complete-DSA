#include <stdio.h>
#include <stdlib.h>


int main(void)
{

    int arr[] = {1,2,3,4,5,6};

    int sizeofarr = sizeof(arr) / sizeof(arr[0]);

    int start = 0;
    int end = sizeofarr - 1;

    while(start < end)
    {
        printf("[S] index : %d value : %d \n " , start , arr[start]);
        printf("[E] index : %d value : %d \n " , end , arr[end]);
        start++;
        end--;

        if(start == end)
        {
            printf("[E] index : %d value : %d \n " , end , arr[end]);
            break;
        }
    }

    return 0;
}