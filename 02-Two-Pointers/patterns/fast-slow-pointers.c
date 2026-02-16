#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void middleIndexAndValue(int * arr , int sizeofarr)
{
    if(sizeofarr <= 0)
    {
        printf("array is empty\n");
        return;
    }

    int slow = 0;
    int fast = 0;

    while(fast < sizeofarr)
    {
        printf("slow index : %d , value : %d \n" , slow , arr[slow]);
        printf("fast index : %d , value : %d \n" , fast , arr[fast]);

        fast += 2;
        slow += 1;
    }

    printf("middle index found %d " , slow);
}

void circularArrayDetection(int * arr , int sizeofarr)
{
    if(sizeofarr <= 0)
    {
        printf("array is empty\n");
        return;
    }

    int slow = 0;
    int fast = 0;

    while(true) 
    {
        // creating artificial loops
        if(slow >= sizeofarr)
        {
            slow = 0;
        }
        //creating artificial loops
        if(fast >= sizeofarr)
        {
            fast = 0;
        }

        printf("slow index : %d , value : %d \n" , slow , arr[slow]);
        printf("fast index : %d , value : %d \n" , fast , arr[fast]);

        fast += 2;
        slow += 1;

        if(fast == slow)
        {
            printf("loop detected \n");
            break;
        }
    }

}

int main(void)
{
    int arr[] = {1,2,3,4,5};
    
    int sizeofarr = sizeof(arr) / sizeof(arr[0]);

    middleIndexAndValue(arr , sizeofarr);

    circularArrayDetection(arr , sizeofarr);

    return 0;
}
