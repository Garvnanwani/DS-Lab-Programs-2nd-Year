//  WAP to print a 2D array top to bottom and then bottom to top

#include <stdio.h>
int main()
{
    int m, n;
    printf("Enter the size the array : \n");
    scanf("%d %d", &n, &m);
    printf("Enter the elements of the array : \n");
    int a[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    printf("\n");
    for (int col = 0; col < m; col++)
    {
        if (col % 2 == 0)
        {
            for (int row = 0; row < n; row++)
                printf("%d ", a[row][col]);
        }
        else
            for (int row = n - 1; row >= 0; row--)
                printf("%d ", a[row][col]);
    }
}
