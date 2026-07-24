#include <stdio.h>

#define ROWS 8
#define COLS 8

int main()
{
    int arr[ROWS][COLS] = {0};

    /*DISPLAY THE GRID*/
    for (int outer_i = 0; outer_i < ROWS; outer_i++)
    {
        printf("%d ", outer_i + 1); // the numbers for the left side
        for (int inner_i = 0; inner_i < COLS; inner_i++)
        {
            printf("[ ]");
        }
        printf("\n");
    }

    // the letters at the bottom of the grid
    printf("  ");
    for (int letter = 0; letter < COLS; letter++)
    {
        printf(" %d ", 1 + letter);
    }
    printf("\n");


    /*TAKE USER INPUT*/


    return 0;
}