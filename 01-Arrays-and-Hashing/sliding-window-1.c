#include <stdio.h>

int findMaxSum(int array[] , int n , int ws)
{
    int sum = 0;
    int maxsum = 0;
    
    for(int i = 0 ; i < n ; i++)
    {
        sum += array[i];
        
        //substract when window is exceeded
        if(i >= ws)
        {
            sum -= array[i - ws];
        }
        
        //when window is created
        if(i >= ws - 1)
        {
            printf("%d window Sum -> %d \n" , i - 1 , sum);
            
            if(sum > maxsum)
            {
                maxsum = sum;
            }
        }
    }
    
    return maxsum;
}

int main(void) {
    
    int a[] = {100,2,3,4,5,6,7,8,9,10};
    
    int ws = 3;
    
    int n = sizeof(a) / sizeof(a[0]);
    
    printf("\nMax sum -> %d " , findMaxSum(a , n , ws));

    return 0;
}