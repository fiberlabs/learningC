// menu_functions.c

#include <stdio.h>

#include "utils.h"

int get_menu_input()
{
    int x = 0;

    while (x != 1 && x != 2 && x != 3 && x != 4)
    {
        printf("choose an option: ");
        if (scanf("%d", &x) == 1)
        {
            // clear input buffer
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

        if (x != 1 && x != 2 && x != 3 && x != 4) {
            printf("must choose from the options above\ntry again\n");
        }
    }

    return x;
}

int print_menu()
{
    printf("===MENU===\n");
    printf("1. ADD RECORD\n");
    printf("2. VIEW RECORD\n");
    printf("3. LIST ALL\n");
    printf("4. QUIT\n");

    int user_input = get_menu_input();

    return user_input;
}