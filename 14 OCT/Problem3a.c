//  Program to print elemnents of a 2D array column wise

#include <stdio.h>

int main()
{
    int r, c, arr[100][100], i, j;
    printf("Enter no of rows : ");
    scanf("%d", &r);
    printf("Enter no of columns : ");
    scanf("%d", &c);

    printf("Enter elements :\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for (i = 0; i < c; i++)
    {
        for (j = 0; j < r; j++)
        {
            printf("arr[%d][%d] :%d\n", j, i, arr[j][i]);
        }
    }
    return 0;
}
