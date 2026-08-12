#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows = 0;
    printf("how many rows?: ");
    scanf("%d", &rows);

    int cols = 0;
    printf("how many cols?: ");
    scanf("%d", &cols);

    // allocate rows space
    float **heatmap = malloc(rows * sizeof(float *));
    if (heatmap == NULL)
    {
        printf("error in heatmap malloc\n");
        return 1;
    }

    // for each row, allocate cols space
    for (int i = 0; i < rows; i++)
    {
        heatmap[i] = malloc(cols * sizeof(float));
        if (heatmap[i] == NULL)
        {
            printf("error in row[%d] malloc\n", i + 1);
            for (int z = 0; z < i; z++)
            {
                free(heatmap[z]);
            }
            free(heatmap);
            heatmap = NULL;
            return 1;
        }
    }

    // fill the heatmap
    for (int j = 0; j < rows; j++)
    {
        for (int a = 0; a < cols; a++)
        {
            heatmap[j][a] = j * a;
        }
    }

    // print the heatmap
    for (int h = 0; h < rows; h++)
    {
        for (int i = 0; i < cols; i++)
        {
            printf("%.2f\t", heatmap[h][i]);
        }

        printf("\n");
    }

    // free the memory
    for (int i = 0; i < rows; i++)
    {
        free(heatmap[i]);
    }
    free(heatmap);

    return 0;
}