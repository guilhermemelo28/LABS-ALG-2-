#include <stdlib.h>
#include <stdio.h>

int alocMatriz(int ***mat, int x, int y);

int main()
{
    int **point;
    int num;

    scanf("%d", &num);

    printf("%d",alocMatriz(&point, num, num));

        /* Desalocação da memória */
        for (int i = 0; i < num; i++)
        {
            free(point[i]);
        }
        free(point);

    return 0;
}

int alocMatriz(int ***mat, int x, int y)
{
    int i;

    (*mat) = (int **)malloc(y * sizeof(int *));

    if ((*mat) != NULL)
    {
        for (i = 0; i < y; i++)
        {
            (*mat)[i] = (int *)malloc(x * sizeof(int));

            if ((*mat)[i] != NULL)
            {
                for (int j = 0; j < x; j++)
                {
                    (*mat)[i][j] = 0;
                }
            }
        }
        return 1;
    }

    return 0;
}