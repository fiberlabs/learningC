// menu_functions.c

#include <stdio.h>
#include <stdlib.h>

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


// VIEW RECORD LOGIC
int list_indexes() {
    struct Record recieve_index = {0};

    FILE *fp = NULL;
    fp = fopen("records.dat", "rb");
    if (fp == NULL) {
        perror("fopen() for list_indexes() returned NULL");
        exit(1);
    }

    int index = 1;

    printf("\n");

    while (fread(&recieve_index, sizeof(struct Record), 1, fp) == 1) 
    {
        printf("%d. %s\n", index, recieve_index.name);
        index++;
    }

    printf("\n");

    if (fclose(fp) != 0)
    {
        perror("fclose() for list_indexes() failed");
        exit(1);
    }

    fp = NULL;

    int user_input = 0;
    while (user_input <= 0 || user_input > (index - 1))
    {
        printf("choose an index: ");
        if (scanf("%d", &user_input) == 1)
        {
            // clear input buffer
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

        if (user_input <= 0 || user_input > (index - 1)) {
            printf("invalid input, you have to choose from the available indexes\n");
        }
    }
    
    return user_input;
}