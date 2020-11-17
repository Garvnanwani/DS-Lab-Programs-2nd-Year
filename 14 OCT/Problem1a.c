// Program to reverse a 1D Array

#include <stdio.h>

int main()
{
    int arr[100], n, i, temp;
    printf("Enter no of Elements : ");
    scanf("%d", &n);

    printf("Enter elements : \n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }

    printf("Reverse :\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
