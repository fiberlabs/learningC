#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char text[500];
    int chars = 0; // to count the chars
    int words = 0;
    int sentences = 0;
    int inside_word = 0; // bool variable... 0 for not in a word, 1 for inside a word

    // take user input
    printf("Enter a paragraph: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    // now we loop through the string
    for (int i = 0; text[i] != '\0'; i++)
    { // as long as the char is not the nullbyte, keep going
        char c = text[i];

        chars++;

        // if we see a ., !, or ?... that means we have completed a sentence
        if (c == '.' || c == '!' || c == '?')
        {
            sentences++;
        }

        // if we run into a space, that means a word is complete
        if (isspace(c))
        {
            // if the char is a whitespace, it means we are now outside a word
            inside_word = 0;
        }
        else
        {
            // if the char is not whitespace and we were outside a word, new word starts
            if (!inside_word)
            {
                words++;
                inside_word = 1;
            }
        }
    }

    printf("characters: %d\n", chars);
    printf("words: %d\n", words);
    printf("sentences: %d\n", sentences);

    return 0;
}