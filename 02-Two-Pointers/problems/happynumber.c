// Happy Number Problem Using Slow and Fast Pointers
#include <stdio.h>
#include <stdbool.h>

int sumofSquare(int number)
{
    int sum = 0;
    while(number > 0)
    {
        int digit = number % 10;
        sum += (digit * digit);
        number /= 10;
    }
    
    return sum;
}

bool isHappyNumber(int n)
{
    
    int slow = n;
    int fast = n;
    
    printf("%d number : " , n);

    while (true) 
    {
        
    slow = sumofSquare(slow);
    printf("slow : %d \n" , slow);
    fast = sumofSquare(sumofSquare(fast));
    printf("fast : %d \n" ,fast);
    
    if (slow == 1 || fast == 1)  // happy number found
        return true;
    
    if (slow == fast)  // cycle detected
        return false;
    }

}

bool isHappyNumberWithFloyd(int n)
{
    
    int slow = n;
    int fast = n;
    do 
    {
        slow = sumofSquare(slow);
        printf("slow : %d \n" , slow);
        fast = sumofSquare(sumofSquare(fast));
        printf("fast : %d \n" ,fast);
    }
    while(slow != fast);
    
    return slow == 1;

}

int main(void) {
    
    printf("Try programiz.pro \n");
    
    printf("%d " , isHappyNumberWithFloyd(22));
    printf("\n");
    printf("%d " , isHappyNumberWithFloyd(1));
}