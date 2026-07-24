#include <stdio.h>

int main()
{
    int wall_tally = 0;
    int tile_tally = 0;
    int player_rowindex = 0;
    int player_colindex = 0;
    
    int arr[5][5] = {
        {1, 1, 1, 1, 1},
        {1, 2, 0, 0, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1}};

    for (int oi = 0; oi < 5; oi++)
    {
        for (int ii = 0; ii < 5; ii++)
        {
            if (arr[oi][ii] == 0)
            {
                tile_tally++;
                printf(".");
            }

            if (arr[oi][ii] == 1)
            {
                wall_tally++;
                printf("#");
            }

            if (arr[oi][ii] == 2)
            {
                player_rowindex = oi + 1; //doing + 1 cuz technically the first row is row 0
                player_colindex = ii + 1; 
                printf("@");
            }
        }
        printf("\n");
    }

    printf("there are %d walls, %d empty tiles and the player is located at row %d column %d\n", wall_tally, tile_tally, player_rowindex, player_colindex);

    return 0;
}