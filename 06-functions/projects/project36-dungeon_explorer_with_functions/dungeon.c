#include <stdio.h>
#include <string.h>

struct Player
{
    int health;
    int attack_dmg;
    int potions;
    int gold;
};

void start_menu();

int main()
{
    // creating a player
    struct Player user;
    user.health = 30;
    user.gold = 0;
    user.potions = 1;

    start_menu();

    return 0;
}

void start_menu()
{
    // print the start menu, and take user input
    printf("welcome to the dungeon explorer!\n");
    printf("to win the game, you must survive all 5 rooms\n");

    char smenu_buffer[10]; // start menu buffer
    while (1)
    {
        printf("do you want to start? (yes/no): ");
        fgets(smenu_buffer, sizeof(smenu_buffer), stdin);
        smenu_buffer[strcspn(smenu_buffer, "\n")] = 0;

        if (strcmp(smenu_buffer, "yes") != 0 && strcmp(smenu_buffer, "no") != 0) {
            printf("invalid input, try again\n");
            continue;
        }
        else if (strcmp(smenu_buffer, "no") == 0) {
            printf("goodbye!\n");
            break;
        }
        else {
            //start the game
            printf("starting game\n");
            break;
        }
    }
}