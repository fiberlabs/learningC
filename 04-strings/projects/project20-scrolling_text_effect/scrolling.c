#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {

    char text[] = "LOADING...";

    size_t length = strlen(text);

    for (size_t i = 0; i < length; i++)
    {
        usleep(300000);
        printf("%s\n", text + i);
    }
    return 0;
}