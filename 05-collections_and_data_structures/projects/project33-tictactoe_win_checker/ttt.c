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
    // checking columns
    for (int j = 0; j < 3 && !winner_found; j++)
    {
        if (board[0][j] != '.' &&
            board[0][j] == board[1][j] &&
            board[1][j] == board[2][j])
        {
            winner = board[0][j];
            winner_found = 1;
        }
    }

    // checking rows
    for (int i = 0; i < 3 && !winner_found; i++)
    {
        if (board[i][0] != '.' &&
            board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
        {
            winner = board[i][0];
            winner_found = 1;
        }
    }

    // checking diagonal 1
    if (!winner_found)
    {
        if (board[0][0] != '.' &&
            board[0][0] == board[1][1] &&
            board[1][1] == board[2][2])
        {
            winner = board[0][0];
            winner_found = 1;
        }
    }

    // checking diagonal 2
    if (!winner_found)
    {
        if (board[0][2] != '.' &&
            board[0][2] == board[1][1] &&
            board[1][1] == board[2][0])
        {
            winner = board[0][2];
            winner_found = 1;
        }
    }

    // printing result logic
    if (winner_found)
    {
        printf("Winner: %c\n", winner);
    }
    else
    {
        printf("No winner.\n");
    }

    return 0;
}