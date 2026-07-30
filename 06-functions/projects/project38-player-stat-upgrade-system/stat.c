#include <stdio.h>

struct Player
{
    int hp;
    int strength;
    int level;
};

struct Player init_player(int hpPara, int strengthPara, int levelPara)
{
    struct Player mc;
    mc.hp = hpPara;
    mc.strength = strengthPara;
    mc.level = levelPara;

    return mc;
}

void level_up(struct Player *main_characterPara) {
    main_characterPara->hp += 10;
    main_characterPara->strength += 5;
    main_characterPara->level ++;
}

int main()
{
    // create the player
    struct Player main_character = init_player(55, 60, 1);

    // print their stats before upgrading
    printf("Player HP: %d, Strength: %d, Level: %d\n", 
        main_character.hp, main_character.strength, main_character.level);
        
    level_up(&main_character);

    // print their stats after upgrading
    printf("Player HP: %d, Strength: %d, Level: %d\n", 
        main_character.hp, main_character.strength, main_character.level);

    return 0;
}