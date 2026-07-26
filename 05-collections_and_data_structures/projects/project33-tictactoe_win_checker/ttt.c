#include <stdio.h>

int main()
{
    int game_won = 0; //bool
    char board[3][3] = {
        {'0', '0', 'X'},
        {'0', 'X', '0'},
        {'X', '0', '0'}
    };

    printf("BOARD:-\n");
    for (int o = 0; o < 3; o++) {

        for (int i = 0; i < 3; i++) {
            printf("%c ", board[o][i]);
        }
        printf("\n");
    }

    char winning_player = '.';
    while(1) {

        if (!game_won) {
            //row condition
            for (int row = 0; row < 3; row++) {
                if (board[row][0] == board[row][1] && board[row][1] == board[row][2] && board[row][0] != '.') {
                    winning_player = board[row][0];
                    game_won = 1;
                 }
            }
        }

        if (!game_won) {
            //vert condition
            for (int col = 0; col < 3; col++) {
                if (board[0][col] == board[1][col] && board[1][col] == board[2][col] && board[0][col] != '.') {
                    winning_player = board[0][col];
                    game_won = 1;
                }
            }
        }

        if (!game_won) {
            //diagonal 1 (top left to bottom right)
            if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '.') {
                winning_player = board[0][0];
                game_won = 1;
            }
        }

        if (!game_won) {
            //diagonal 2 (top right to bottom left)
            if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '.') {
                winning_player = board[0][2];
                game_won = 1;
            }
        }

        break;
    }

    if (game_won) {
        printf("%c is the winner\n", winning_player);
    }

    return 0;
}