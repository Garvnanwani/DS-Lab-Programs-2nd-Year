//  WAP to sort an array using Bubble Sort

#include <stdio.h>

void swap(int *x, int *y);
void bubbleSort(int arr[], int n);

int main()
{
    int n;
    printf("Enter the number of elements in the array : \n");
    scanf("%d", &n);
    int arr[n];
    printf("\nEnter the elements of the array : \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
