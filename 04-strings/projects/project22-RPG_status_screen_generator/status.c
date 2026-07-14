#include <stdio.h>
#include <string.h>

int main()
{
    //code
    char buffer[1000];

    //name
    char name[50];
    printf("enter the character's name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    //level
    char level[50];
    printf("enter the character's level: ");
    fgets(level, sizeof(level), stdin);
    level[strcspn(level, "\n")] = '\0';

    //HP
    int hp = 0;
    printf("enter the character's HP: ");
    scanf("%d", &hp);

    //name
    int gold = 0;
    printf("enter the character's gold: ");
    scanf("%d", &gold);

    snprintf(buffer, sizeof(buffer), "========\nName: %s\nLevel: %s\nHP: %d\nGold: %d\n========\n", name, level, hp, gold);

    printf("%s", buffer);

    return 0;
}