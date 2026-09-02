#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Quest
{
    char title[50];
    struct Quest *next;
};

static struct Quest *first_quest = NULL;

struct Quest *add_quest(char *name)
{
    struct Quest *new_quest = malloc(sizeof(struct Quest));
    if (new_quest == NULL)
    {
        printf("error: malloc for new_quest");
        return NULL;
    }

    strcpy(new_quest->title, name);
    new_quest->next = NULL;

    if (first_quest == NULL) {
        first_quest = new_quest;
        return new_quest;
    }

    struct Quest *current_quest = NULL;
    current_quest = first_quest;
    while (current_quest->next != NULL) {
        current_quest = current_quest->next;
    }
    current_quest->next = new_quest;
}

int main()
{

    return 0;
}