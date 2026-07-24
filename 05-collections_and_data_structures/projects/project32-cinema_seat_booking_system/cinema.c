#include <stdio.h>

#define ROWS 5
#define COLS 5

int main()
{
    int arr[ROWS][COLS] = {0};
    while (1)
    {
        /*DISPLAY THE GRID*/
        printf("\n");
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

        while (1)
        {
            printf("what is the ROW of the seat you want to book?: ");
            scanf("%d", &row_input);

            if (row_input > ROWS || row_input <= 0)
            {
                printf("invalid input, try again\n");
                continue;
            }
            else
            {
                break;
            }
        }

        while (1)
        {
            printf("what is the COLUMN of the seat you want to book?: ");
            scanf("%d", &col_input);

            if (col_input > COLS || col_input <= 0)
            {
                printf("invalid input, try again\n");
                continue;
            }
            else
            {
                break;
            }
        }

        // to match the grid display
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

        /*ask the user if they want to quit*/
        int user_input = 0;
        printf("do you want to quit the program (1 for yes, 0 for no)?: ");
        scanf("%d", &user_input);

        if (user_input == 1) {
            printf("goodbye\n");
            return 0;
        }
    }

    return 0;
}