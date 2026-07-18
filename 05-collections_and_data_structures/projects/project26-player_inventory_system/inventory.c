#include <stdio.h>

#define CAP 5

int main()
{
    int inventory[CAP] = {10, 20, 30, 0, 0};
    int count = 3;

    while (1)
    {
        // print menu and take user input
        int menu_input = 100; // dummy val

        while (menu_input != 1 && menu_input != 2 && menu_input != 3 && menu_input != 4)
        {
            printf("\n");
            printf("========== MENU ==========\n");
            printf("1. Add Item\n");
            printf("2. Drop Last Item\n");
            printf("3. Show Inventory\n");
            printf("4. Exit Program\n");
            printf("==========================\n");

            printf("choose an option: ");
            scanf("%d", &menu_input);

            if (menu_input != 1 && menu_input != 2 && menu_input != 3 && menu_input != 4)
            {
                printf("invalid input, try again\n");
            }
        }

        // game logic
        int add_input = 0;
        int exit_program = 0; //bool
        switch (menu_input)
        {
        case 1:
            // add item logic

            if (count < CAP) // bounds check
            {
                // print the existing items
                for (int i = 0; i < count; i++)
                {
                    printf("SLOT %d: %d\n", i, inventory[i]);
                }
                // ask the user to enter an item ID
                printf("enter an item ID: ");
                scanf("%d", &add_input);

                // add it to the array
                inventory[count] = add_input;
                count++;
            }
            else
            {
                printf("inventory is full...\n");
            }

            break;

        case 2:
            printf("drop item logic\n");
            break;

        case 3:
            // show inventory logic
            if (count > 0)
            {
                for (int i = 0; i < count; i++)
                {
                    printf("SLOT %d: %d\n", i, inventory[i]);
                }
            }
            else
            {
                printf("inventory is empty\n");
            }

            break;

        case 4:
            // exit program logic
            exit_program = 1;
            printf("goodbye...\n");

            break;

        default:
            printf("invalid input or something went wrong\n");
            break;
        }

        if (exit_program){
            break;
        }
    }

    return 0;
}