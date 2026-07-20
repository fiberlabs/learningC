#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

struct Fighter
{
    char name[100];
    int hp;
    int attack_dmg;
};

int main()
{
    srand(time(NULL));

    int player1_won = 0; // boolean vars
    int player2_won = 0;
    int round_tally = 0;

    struct Fighter player1;
    strcpy(player1.name, "Kratos");
    player1.hp = 100;
    player1.attack_dmg = 1 + rand() % 10; // damage between 1 and 10 per attack

    struct Fighter player2;
    strcpy(player2.name, "Thor");
    player2.hp = 100;
    player2.attack_dmg = 1 + rand() % 10; // damage between 1 and 10 per attack

    while (player1.hp > 0 && player2.hp > 0) // run as long as both player's health is > 0
    {
        // player1 attacks first
        round_tally++;
        printf("ROUND: %d\n", round_tally);
        printf("\n");
        printf("%s HP: %d\n%s HP: %d\n", player1.name, player1.hp, player2.name, player2.hp);
        printf("%s is attacking %s!\n", player1.name, player2.name);
        player2.hp -= player1.attack_dmg;

        if (player2.hp <= 0 && player1.hp > 0)
        {
            player1_won = 1;
            break;
        }

        // now player2 attacks player1
        printf("\n");
        printf("%s HP: %d\n%s HP: %d\n", player1.name, player1.hp, player2.name, player2.hp);
        printf("%s is attacking %s!\n", player2.name, player1.name);
        player1.hp -= player2.attack_dmg;

        if (player1.hp <= 0 && player2.hp > 0)
        {
            player2_won = 1;
            break;
        }
    }

    if (player1_won)
    {
        printf("%s was slain by %s\n", player2.name, player1.name);
    }

    if (player2_won)
    {
        printf("%s was slain by %s\n", player1.name, player2.name);
    }

    return 0;
}