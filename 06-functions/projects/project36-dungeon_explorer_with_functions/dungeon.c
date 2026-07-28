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
    int attack_dmg; // this wull be randomly generated every turn
    int potions;
    int gold;
    enum CharacterStatus status;
};

struct Monster
{
    int health;
    int attack_dmg; // this will be randomly generated every turn
    enum CharacterStatus status;
};

// function signatures
void start_menu();
void start_game();
int room_chance();
void treasure_room(struct Player *user);
void user_rest(struct Player *user);
void trap_room(struct Player *user);
void monster_room(struct Player *user, struct Monster *monster);
int monster_room_menu(struct Player *user, struct Monster *monster);
void drink_potion(struct Player *user);
void attack_sequence(struct Player *user, struct Monster *monster);

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
            // create the monster
            struct Monster monster;
            monster.health = 5 + rand() % 11;
            monster.status = ALIVE;

            monster_room(&user, &monster);
        }
        else if (scenario <= 7)
        {
            treasure_room(&user);
        }
        else if (scenario <= 9)
        {
            trap_room(&user);
        }
        else
        {
            printf("you found a empty room\n");
        }

        if (user.status == DEAD)
        {
            printf("game over\n");
            return;
        }

        if (room != 5)
        {
            user_rest(&user);
        }

        if (user.health > 0 && room == 5) {
            printf("you win... you survived all 5 rooms\n");
            return;
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

void user_rest(struct Player *user)
{
    char rest_buffer[10];

    while (1)
    {
        printf("current HP: %d\n", user->health);
        printf("do you want to rest (+5 HP)? (yes/no): ");
        fgets(rest_buffer, sizeof(rest_buffer), stdin);
        rest_buffer[strcspn(rest_buffer, "\n")] = 0;

        if (strcmp(rest_buffer, "yes") != 0 && strcmp(rest_buffer, "no") != 0)
        {
            printf("invalid input, try again\n");
            continue;
        }
        else if (strcmp(rest_buffer, "no") == 0)
        {
            printf("continuing journey...\n");
            break;
        }
        else
        {
            if (user->health >= 50)
            {
                printf("you are already at max health... can not heal further\n");
                continue;
            }
            else
            {
                user->health += 5;
                if (user->health > 50)
                {
                    user->health = 50;
                }
                printf("you now have %d health\n", user->health);
                continue;
            }
        }
    }
}

void trap_room(struct Player *user)
{
    printf("OH NO! you fell into a trap room! :(\n");
    int hp_lost = 5 + rand() % 11;
    user->health -= hp_lost;

    if (user->health <= 0)
    {
        user->status = DEAD;
    }
    else
    {
        printf("you took %d damage\n", hp_lost);
        printf("you have %d HP left...\n", user->health);
    }
}

void monster_room(struct Player *user, struct Monster *monster) // test it out now
{
    int user_input;

    while (1)
    {
        int user_input = monster_room_menu(user, monster);

        // if they want to drink a potion
        if (user_input == 2)
        {
            drink_potion(user);
        }
        else if (user_input == 1)
        {
            attack_sequence(user, monster);

            if (monster->status == DEAD)
            {
                printf("You survived the encounter!\n");
                break;
            }

            if (user->status == DEAD)
            {
                break;
            }
        }

        else
        {
            printf("still have to write this logic\n");
        }
    }
}

int monster_room_menu(struct Player *user, struct Monster *monster)
{
    printf("entering roo...A MONSTER HAS APPEARED!\n");

    printf("your HP:   \t%d\n", user->health);
    printf("Potions:   \t%d\n", user->potions);
    printf("Monster HP:\t%d\n", monster->health);

    // take monster menu input
    char monster_menu_buffer[10];
    int mm_valid_input = 0; // mm means monster menu
    while (1)
    {
        printf("'1' for attack and '2' for potion\n");

        printf("do you want to attack or drink potion(+10HP)?: ");
        fgets(monster_menu_buffer, sizeof(monster_menu_buffer), stdin);
        monster_menu_buffer[strcspn(monster_menu_buffer, "\n")] = '\0';

        if (strcmp(monster_menu_buffer, "1") != 0 && strcmp(monster_menu_buffer, "2") != 0)
        {
            printf("invalid input, try again\n");
            continue;
        }
        else
        {
            mm_valid_input = 1;
        }

        if (mm_valid_input)
        {
            return atoi(monster_menu_buffer);
        }
    }
}

void drink_potion(struct Player *user)
{
    if (user->health >= 50)
    {
        printf("your health is already full\n");
        return;
    }
    else
    {
        if (user->potions > 0)
        {
            user->potions--;
            user->health += 10;

            if (user->health > 50)
            {
                user->health = 50;
                printf("using potion... you now have %d health\n", user->health);
                return;
            }

            printf("using potion... you now have %d health\n", user->health);
            return;
        }
        else
        {
            printf("you dont have any potions left\n");
            return;
        }
    }
}

void attack_sequence(struct Player *user, struct Monster *monster)
{
    // ---------- Player attacks ----------
    user->attack_dmg = 5 + rand() % 11; // 5-15

    printf("\nYou attack the monster for %d damage!\n", user->attack_dmg);

    monster->health -= user->attack_dmg;

    if (monster->health <= 0)
    {
        monster->health = 0;
        monster->status = DEAD;

        printf("The monster has been defeated!\n");
        return;
    }

    printf("Monster HP: %d\n", monster->health);

    // ---------- Monster attacks ----------
    monster->attack_dmg = 5 + rand() % 11; // 5-15

    printf("The monster attacks you for %d damage!\n", monster->attack_dmg);

    user->health -= monster->attack_dmg;

    if (user->health <= 0)
    {
        user->health = 0;
        user->status = DEAD;

        printf("You have been slain!\n");
        return;
    }

    printf("Your HP: %d\n\n", user->health);
}