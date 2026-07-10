#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int player_health = 30;
    int potions = 1;
    int gold = 0;

    for (int room = 1; room <= 5; room++)
    {
        int room_chance = 1 + (rand() % 10); // will generate a number bw 1 and 10

        if (room_chance <= 4)
        {
            // monster room logic
            printf("entering roo...A MONSTER HAS APPEARED!\n");

            // display menu
            int monster_health = 5 + rand() % 11; // will generate a value bw 5-15

            while (1)
            {
                printf("Your HP:      \t%d\n", player_health);
                printf("Your Potions: \t%d\n", potions);
                printf("Monster HP:   \t%d\n", monster_health);

                // take user input
                char monster_room_input = 'a'; // dummy char value
                while (monster_room_input != 'A' && monster_room_input != 'P')
                {
                    printf("[A]ttack or drink [P]otion (+10HP)?: ");
                    scanf(" %c", &monster_room_input);

                    if (monster_room_input != 'A' && monster_room_input != 'P')
                    {
                        printf("invalid input, try again...\n");
                        continue;
                    }
                }

                // monster room loop logic

                switch (monster_room_input)
                {
                // if the player chose to drink a potion
                case 'P':
                    // first check if the player has a potion
                    if (potions > 0)
                    {
                        if (player_health >= 50)
                        {
                            player_health = 50; // just to make sure it doesnt go past 50
                            printf("you are already at full health! no potions used\n");
                            printf("you still have %d", potions);
                        }
                        else
                        {
                            potions--;
                            player_health += 10;
                            player_health = player_health >= 50 ? 50 : player_health;
                            printf("you now have %d HP\n", player_health);
                        }
                    }
                    else
                    {
                        printf("you have no potions, cant heal\n");
                        continue; // will go back to the top of the while(1)
                    }

                    break;

                // if the player chose to attack the monster
                case 'A':
                    int player_attack_dmg = 3 + rand() % 6;
                    printf("you dealt %d damage\n", player_attack_dmg);
                    monster_health -= player_attack_dmg;
                    printf("monster HP is now: %d\n", monster_health);
                    // now time for the monster attack
                    if (monster_health > 0)
                    {
                        int monster_attack_dmg = 2 + rand() % 5;
                        printf("monster is now attacking... you lost %d HP\n", monster_attack_dmg);
                        player_health -= monster_attack_dmg;
                        printf("your HP is now: %d\n", player_health);
                    }
                    else
                    {
                        printf("you slain the monster!\n");
                    }
                    break;

                default:
                    printf("error for some reason... default in switch monster room\n");
                    break;
                }

                if (player_health <= 0)
                {
                    printf("you lost the battle :(... game over\n");
                    return 1;
                }
                else if (player_health >= 0 && monster_health <= 0)
                {
                    printf("you slain the monster!\n");

                    // reward
                    int monster_gold_drop = 5 + rand() % 11;
                    int monster_potion_drop = 1 + rand() % 10;

                    if (monster_potion_drop <= 2)
                    {
                        printf("monster dropped %d gold and 1 potion!", monster_gold_drop);
                        gold += monster_gold_drop;
                        potions++;
                        printf("you now have %d gold and %d potion(s)\n", gold, potions);
                    }
                    else
                    {
                        printf("monster dropped %d gold!", monster_gold_drop);
                        gold += monster_gold_drop;
                        printf("you now have %d gold and %d potion(s)\n", gold, potions);
                    }
                    break;
                }
            }
        }
        else if (room_chance <= 7)
        {
            // treasure room logic
            int gold_found = 10 + rand() % 21; // will give a value bw 10-30
            int potion_found = 1 + rand() % 4; // will give 1-4, if it gets 1, then its 25%... chose 1 for 25% cuz i mean, it works
            printf("you found a treasure room!\n");

            if (potion_found == 1)
            {
                printf("you found %d gold and 1 potion\n", gold_found);
                gold += gold_found;
                potions++;
                printf("you now have %d gold coins and %d potion(s)\n", gold, potions);
            }
            else
            {
                printf("you found %d gold but no potions\n", gold_found);
                gold += gold_found;
                printf("you now have %d gold coins and %d potion(s)\n", gold, potions);
            }
        }
        else if (room_chance <= 9)
        {
            // trap room logic
            int trap_dmg = 5 + rand() % 11; // will give a value bw 5-15
            player_health -= trap_dmg;
            printf("you entered a trap room, you took %d damage...\nnew health:\t%d\n", trap_dmg, player_health);

            if (player_health <= 0)
            {
                printf("you died :(\ngame over....\n");
                return 0;
            }
        }
        else
        {
            // empty room logic
            printf("you found an empty room... moving onto the next room\n");
        }

        // if player is still alive after room number 5, end the game
        if (player_health > 0 && room == 5)
        {
            printf("you survived all 5 rooms, you win!\n");
            break; // will exit the while loop
        }

        // between rooms logic
        char rest_input = 'a'; // 'a' is just a dummy value

        if (player_health > 0 && room <= 5)
        {
            while (rest_input != 'C')
            {
                // display current health, potions and gold
                printf("===== STATS =====\n");
                printf("HP:     \t%d\n", player_health);
                printf("Potions:\t%d\n", potions);
                printf("Gold:   \t%d\n", gold);

                // now ask the user if they want to rest or continue
                printf("[R]est (heal 5 HP) or [C]ontinue to next room?: ");
                scanf(" %c", &rest_input);

                switch (rest_input)
                {

                case 'C':
                    printf("moving onto next room...\n");
                    break;

                case 'R':

                    if (player_health >= 50)
                    {
                        printf("HP is already full\n");
                    }
                    else
                    {
                        player_health += 5;
                        if (player_health >= 50) {
                            player_health = 50;
                        }
                        printf("new HP: %d", player_health);
                    }
                    break;

                default:
                    printf("invalid input, try again\n");
                    break;
                }
            }
        }
    }

    return 0;
}