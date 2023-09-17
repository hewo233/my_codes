#include <stdio.h>
#include <math.h>

#define MAX_SIZE 100

int determinant(int matrix[MAX_SIZE][MAX_SIZE], int n)
{
    int det = 0;
    int submatrix[MAX_SIZE][MAX_SIZE];
    
    if (n == 2)
    {
        return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    }
    else
    {
        for (int x = 0; x < n; x++)
        {
            int subi = 0;
            for (int i = 1; i < n; i++)
            {
                int subj = 0;
                for (int j = 0; j < n; j++)
                {
                    if (j == x)
                        continue;
                    submatrix[subi][subj] = matrix[i][j];
                    subj++;
                }
                subi++;
            }
            det += pow(-1, x) * matrix[0][x] * determinant(submatrix, n - 1);
        }
    }
    
    return det;
}

void getMatrix(int matrix[MAX_SIZE][MAX_SIZE], int n)
{
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int n)
{
    printf("The matrix is:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    int matrix[MAX_SIZE][MAX_SIZE];
    
    printf("Enter the order of the matrix (less than %d): ", MAX_SIZE);
    scanf("%d", &n);
    
    if (n <= 0 || n > MAX_SIZE)
    {
        printf("Invalid matrix size.\n");
        return 1;
    }
    
    getMatrix(matrix, n);
    printMatrix(matrix, n);
    
    int det = determinant(matrix, n);
    printf("The determinant is: %d\n", det);
    
    return 0;
}