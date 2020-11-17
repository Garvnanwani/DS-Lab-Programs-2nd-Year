// Program to add two 2D arrays of size 3 * 3

#include <stdio.h>

int main()
{
    int a[3][3], b[3][3], i, j, ans[3][3];
    printf("Enter elements of 1st array :\n");

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter elements of 2nd array :\n");

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            ans[i][j] = a[i][j] + b[i][j];
        }
    }

    printf("Result :\n");

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", ans[i][j]);
        }
        printf("\n");
    }

    return 0;
}
