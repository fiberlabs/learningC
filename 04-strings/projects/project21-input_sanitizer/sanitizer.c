#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char buffer[100];

    // take user input
    printf("enter your password: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    // using strlen instead of sizeof because we want to know how many bytes the actual string is using
    // not the total bytes in buffer[]
    size_t length = strlen(buffer); //this is better for when we have to use larger strings
    for (size_t i = 0; i < length; i++)
    {
        // first check for any punctuation characters in the string
        if (ispunct(buffer[i]) != 0)
        {
            // if it is a punct character, then check for any dangerous input
            // you dont want to reject every punct char, only the dangerous ones
            if (buffer[i] == ';' || buffer[i] == '|' || buffer[i] == '&')
            {
                printf("Potential command injection detected.... exiting program\n");
                return 1;
            }
        }
    }

    // if nothing bad was detected
    printf("you entered: %s\n", buffer);

    return 0;
}