#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

enum CharacterStatus
{
    ALIVE,
    DEAD
};

struct Player
{
    int health;
    int attack_dmg;
    int potions;
    int gold;
    enum CharacterStatus status;
};

void start_menu();
void start_game();
int room_chance();
void treasure_room(struct Player *user);

int main()
{
    srand(time(NULL));

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

        if (strcmp(smenu_buffer, "yes") != 0 && strcmp(smenu_buffer, "no") != 0)
        {
            printf("invalid input, try again\n");
            continue;
        }
        else if (strcmp(smenu_buffer, "no") == 0)
        {
            printf("goodbye!\n");
            break;
        }
        else
        {
            // start the game
            start_game();
            break;
        }
    }
}

void start_game()
{

    // create the player's character
    struct Player user;
    user.health = 30; // max is 50
    user.gold = 0;
    user.potions = 1;
    user.status = ALIVE;

    for (int room = 1; room < 6; room++)
    {
        // generate the room chance
        int scenario = room_chance();

        printf("room number: %d\n", room);

        if (scenario <= 4)
        {
            printf("monster room\n");
        }
        else if (scenario <= 7)
        {
            treasure_room(&user);
        }
        else if (scenario <= 9)
        {
            printf("trap room\n");
        }
        else
        {
            printf("empty room\n");
        }
    }
}

int room_chance()
{
    return 1 + rand() % 10;
}

void treasure_room(struct Player *user)
{
    int gold_found = 10 + rand() % 21;
    int found_potion = rand() % 2; // bool

    if (!found_potion)
    {
    printf("you stumbled into a treasure room!\n");
	printf("you found %d gold!\n", gold_found);
	user->gold += gold_found;
	printf("you now have %d gold and %d potion(s)\n", user->gold, user->potions);
    }
    else
    {
    printf("you stumbled into a treasure room!\n");
	printf("you found %d gold and 1 potion!\n", gold_found);
	user->gold += gold_found;
	user->potions++;
	printf("you now have %d gold and %d potion(s)\n", user->gold, user->potions);
    }
}