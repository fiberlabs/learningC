#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int total_bytes = 8; // starting with 8 bytes
    int bytes_used = 0;  // to keep track of the number of bytes used

    char *buffer = malloc(total_bytes * sizeof(char));

    if (buffer == NULL)
    {
        printf("error occured in og malloc\n");
        return 1;
    }

    //take user input
    char input_buffer[4096]; // have to fix this in the morning
    printf("enter some input: ");
    fgets(input_buffer, sizeof(input_buffer), stdin);
    input_buffer[strcspn(input_buffer, "\n")] = '\0';
    

    // count the number of bytes used
    for (size_t i = 0; i < strlen(input_buffer); i++)
    {
        bytes_used++;
    }

    // now the increase size logic
    while (1)
    {
        if (bytes_used > total_bytes - 1)
        {
            char *temp = realloc(buffer, total_bytes * 2 * sizeof(char));

            if (temp == NULL)
            {
                printf("error occured in og malloc\n");
                free(buffer);
                buffer = NULL;
                return 1;
            }

            total_bytes *= 2;
            buffer = temp;
            continue;
        }
        else
        {
            break;
        }
    }

    // loop over array and put in the index of buffer (aka fill the string)
    for (int i = 0; i <= bytes_used; i++) {
        buffer[i] = input_buffer[i];
    }
    //now add the nullbyte
    buffer[bytes_used] = '\0';
    //now print to screen
    printf("printed: %s\n", buffer);

    return 0;
}