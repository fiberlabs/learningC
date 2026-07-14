#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char buffer[100];

    // take user input
    printf("enter your username: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    /*STEP 1: remove the whitespaces before the text*/
    int prev_whitespaces = 0;
    for (size_t i = 0; i < strlen(buffer) && isalnum(buffer[i]) == 0; i++) // as long as i is < strlen AND i stop at the first alphanumeric value
    {
        if (isspace(buffer[i]) != 0) // if char is a space, then incremenet the tally
        {
            prev_whitespaces++;
        }
    }

    // save the changes to the original array, using memmove() over snprintf() here because i dont want the overlap problem
    memmove(buffer, buffer + prev_whitespaces, strlen(buffer + prev_whitespaces) + 1); //+1 for the null terminator

    /*STEP 2: remove the whitespaces after the text*/
    size_t post_whitespaces = 0;
    size_t length = strlen(buffer);
    for (size_t i = length - 1; i > 0 && isspace(buffer[i]) != 0; i--) // if IT IS a whitespace, then increment the tally... did i > 0 to prevent
    //                                                                                                                       undefined behaviour
    {
        post_whitespaces++;
    }

    buffer[length - post_whitespaces] = '\0';

    /*STEP 3: remove any whitespaces between the text e.g 'fiber labs' needs to be turned into 'fiber.labs'*/
    char first_word_buffer[50];
    size_t first_word_tally = 0;
    size_t mid_whitespaces = 0;
    char last_word_buffer[50];
    size_t last_word_tally = 0;

    size_t length_step3 = strlen(buffer);
    // find out the length of the first word
    for (size_t i = 0; isspace(buffer[i]) == 0; i++) // increment counter until we hit the first white space, this becomes the length of the first word
    {
        first_word_tally++;
    }
    // now we should seperate it into a seperate string
    memmove(first_word_buffer, buffer, first_word_tally);
    first_word_buffer[first_word_tally] = '\0';
    printf("seperated first word: %s\n", first_word_buffer);

    // find out the length of the second word
    for (size_t i = length_step3 - 1; i > 0 && isspace(buffer[i]) == 0; i--)
    {
        last_word_tally++;
    }
    // now seperate it into a seperate string
    memmove(last_word_buffer, buffer + (length_step3 - last_word_tally), last_word_tally);
    last_word_buffer[last_word_tally] = '\0';
    printf("seperated last word: %s\n", last_word_buffer);

    //now we take the two seperated strings and join them together in the proper formatting, then print the result
    snprintf(buffer, sizeof(buffer), "%s.%s@example.com", first_word_buffer, last_word_buffer);
    printf("your email is: %s\n", buffer);


    return 0;
}