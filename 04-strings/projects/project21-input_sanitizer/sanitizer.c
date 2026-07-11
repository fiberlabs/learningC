#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT 100

int main()
{
    char buffer[MAX_INPUT];

    // take user input
    printf("enter your password: ");

    if (fgets(buffer, MAX_INPUT, stdin) == NULL)
    {
        printf("Input Error Occured :(\n");
        return 1;
    }

    buffer[strcspn(buffer, "\n")] = '\0';

    for (int i = 0; buffer[i] != '\0'; i++)
    {

        // if something unsafe was found
        if (buffer[i] == '|' || buffer[i] == ';' || buffer[i] == '&')
        {
            printf("UNSAFE CHARACTER DETECTED!: %c... ending program\n", buffer[i]);
            return 1;
        }
    }

    // if nothing unsafe was found it will do this
    printf("the user input is safe!\n");

    return 0;
}
