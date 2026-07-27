#include <stdio.h>

int calc_dmg(int att, int def);
int crit_hit(int base_dmg);
void print_res(int dmg);

int main()
{
    int player_attack = 10;
    int enemy_defense = 8;

    print_res(crit_hit(calc_dmg(player_attack, enemy_defense)));
}

int calc_dmg(int att, int def)
{
    return att - def;
}

int crit_hit(int base_dmg)
{
    return base_dmg * 2;
}

void print_res(int dmg)
{
    printf("you did %d damage\n", dmg);
}
