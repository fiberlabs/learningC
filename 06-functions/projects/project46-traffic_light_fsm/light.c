#include <stdio.h>
#include <unistd.h>

enum
{
    RED,
    GREEN,
    YELLOW
};

void red()
{
    printf("RED LIGHT\n");
}

void yellow()
{
    printf("YELLOW LIGHT\n");
}

void green()
{
    printf("GREEN LIGHT\n");
}

int main()
{
    void (*colors[])() = {red, green, yellow};
    int transitions[] = {GREEN, YELLOW, RED};

    int current = RED;

    for (int i = 0; i >= 0; i++)
    {
        colors[current]();
        sleep(1);
        current = transitions[current];
    }

    return 0;
}