// Program to find avg of numbers in an array

#include <stdio.h>

int main()
{
    int n, i, j;
    float avg, a[100], sum;
    printf("Enter no of elements : ");
    scanf("%d", &n);

    printf("Enter elements : \n");

    for (i = 0; i < n; i++)
    {
        scanf("%f", &a[i]);
    }

    for (j = 0; j < n; j++)
    {
        sum += a[j];
    }

    avg = sum / n;
    printf("Average : %.3f", avg);
    return 0;
}
