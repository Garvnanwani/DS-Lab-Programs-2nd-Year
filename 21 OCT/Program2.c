// WAP to print even_sum and odd_sum such that if thearray ateven index and number of even index is even then take even_sum. Similarly for odd index and the number of odd index is odd thentake odd_sum.

#include <stdio.h>

int main()
{
    int n;
    printf("enter the no of elements in array : \n");
    scanf("%d", &n);
    printf("enter the elements : \n");
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int even_sum = 0, odd_sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == a[i] % 2)
        {
            if (i % 2 == 0)
                even_sum += a[i];
            else
                odd_sum += a[i];
        }
    }
    printf("even sum is %d\nodd sum is %d", even_sum, odd_sum);
}
