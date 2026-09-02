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

    if (first_quest == NULL)
    {
        first_quest = new_quest;
        return new_quest;
    }

    struct Quest *current_quest = NULL;
    current_quest = first_quest;
    while (current_quest->next != NULL)
    {
        current_quest = current_quest->next;
    }
    current_quest->next = new_quest;

    return new_quest;
}

void print_quests()
{
    if (first_quest == NULL)
    {
        printf("there are no quests to print\n");
        return;
    }

    struct Quest *current_quest = NULL;
    current_quest = first_quest;
    while (current_quest != NULL)
    {
        printf("Title: %s\nMemory Address: %p\n\n", current_quest->title, (void *)current_quest);
        current_quest = current_quest->next;
    }
}

void destroy_quests()
{
    if (first_quest == NULL)
    {
        printf("there are no quests to destroy\n");
        return;
    }

    struct Quest *current_quest = NULL;
    current_quest = first_quest;
    while (current_quest != NULL)
    {
        struct Quest *temp = current_quest->next;
        free(current_quest);
        current_quest = temp;
    }
    first_quest = NULL;
}

int main()
{
    add_quest("slay the dragon");
    add_quest("become elden lord");
    add_quest("leave central yharnam");
    print_quests();
    destroy_quests();

    return 0;
}