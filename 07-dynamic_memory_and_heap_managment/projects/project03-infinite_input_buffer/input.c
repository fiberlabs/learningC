#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int bytes_entered = 0;

    // allocate 8 bytes to start
    int total_bytes = 8;

    char *space_available = malloc(total_bytes * sizeof(char));
    if (space_available == NULL)
    {
        printf("error during malloc\n");
        return 1;
    }

    // take user input
    printf("enter some text: ");
    int user_input;
    while ((user_input = getchar()) != '\n' && user_input != EOF)
    {
        bytes_entered++; // now we know how many bytes are entered

        // size increase (if needed) logic
        while (1)
        {
            if (bytes_entered > total_bytes - 1)
            {
                char *temp = realloc(space_available, total_bytes * 2 * sizeof(char));

                if (temp == NULL)
                {
                    printf("error during realloc\n");
                    free(space_available);
                    space_available = NULL;
                    return 1;
                }

                total_bytes *= 2;
                space_available = temp;
                continue;
            }
            else
            {
                break;
            }
        }

        space_available[bytes_entered - 1] = (char)user_input;
    }

    space_available[bytes_entered] = '\0'; //add the nullbyte

    //now print the output to screen
    printf("you entered: %s\n", space_available);

    //free memory
    free(space_available);  
    space_available = NULL;  

    return 0;
}