#include <stdio.h>

#define ROWS 4
#define COLS 4

int main()
{
    int arr[ROWS][COLS] = {0};

    /*DISPLAY THE GRID*/
    for (int outer_i = 0; outer_i < ROWS; outer_i++)
    {
        printf("%d ", outer_i + 1); // the numbers for the left side
        for (int inner_i = 0; inner_i < COLS; inner_i++)
        {
            if (arr[outer_i][inner_i] == 0)
            {
                printf("[ ]");
            }
            else
            {
                printf("[X]");
            }
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
    int row_input = 0;
    int col_input = 0;

    printf("what is the ROW of the seat you want to book?: ");
    scanf("%d", &row_input);

    printf("what is the COLUMN of the seat you want to book?: ");
    scanf("%d", &col_input);

    //to match the grid display
    row_input--;
    col_input--;

    if (arr[row_input][col_input] == 1)
    {
        printf("seat already booked\n");
    }
    else
    {
        arr[row_input][col_input] = 1;
    }

    /*redisplay the grid with the updated value*/
    for (int outer_i = 0; outer_i < ROWS; outer_i++)
    {
        printf("%d ", outer_i + 1); // the numbers for the left side
        for (int inner_i = 0; inner_i < COLS; inner_i++)
        {
            if (arr[outer_i][inner_i] == 0)
            {
                printf("[ ]");
            }
            else
            {
                printf("[X]");
            }
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

    return 0;
}