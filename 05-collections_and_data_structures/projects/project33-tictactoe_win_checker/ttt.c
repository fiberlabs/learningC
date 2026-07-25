#include <stdio.h>

int main()
{

    char board[3][3] = {
        {'X', 'O', 'X'},
        {'O', 'X', 'O'},
        {'X', '.', '.'}};

    int winner_found = 0;
    char winner = '.';

    // printing the board
    printf("board:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    /*win conditions*/
    

    return 0;
}