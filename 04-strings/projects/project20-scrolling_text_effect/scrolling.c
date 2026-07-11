#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
    char word[50] = "LOADING";

    for (int i = 0; i < strlen(word); i++)
    {
        usleep(300000);
        printf("%s...\n", word + i);
    }

    return 0;
}

