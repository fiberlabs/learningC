#include <stdio.h>

int main()
{
    int user_input;
    printf("enter the size of the grid: ");
    scanf("%d", &user_input);

    for (int row = 1; row <= user_input; row++) 
    {
        for (int col = 1; col <= user_input; col++) 
        {
            printf("%d\t", row * col);
        }

        printf("\n");
    }

    return 0;
}