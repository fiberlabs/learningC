// ./music_player.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

static struct Song *first_song = NULL;
static struct Song *last_song = NULL;

char *get_song_name()
{
    int bytes_used = 0;
    int index = 0;

    int capacity = 8;
    char *string_buffer = malloc(capacity * sizeof(char));
    if (string_buffer == NULL)
    {
        printf("error: malloc for string_buffer\n");
        return NULL;
    }

    printf("enter the song's name: ");
    int name_input;
    while ((name_input = getchar()) != '\n' && name_input != EOF)
    {
        bytes_used++;

        while (1)
        {
            if (bytes_used > capacity - 1)
            {
                char *temp = realloc(string_buffer, (capacity * 2) * sizeof(char));
                if (temp == NULL)
                {
                    printf("error: realloc for temp\n");
                    free(string_buffer);
                    string_buffer = NULL;
                    return NULL;
                }
                capacity *= 2;
                string_buffer = temp;
            }
            else
            {
                break;
            }
        }

        string_buffer[index] = name_input;
        index++;
    }

    string_buffer[bytes_used] = '\0';
    return string_buffer;
}

char *get_artist_name()
{
    int bytes_used = 0;
    int index = 0;

    int capacity = 8;
    char *string_buffer = malloc(capacity * sizeof(char));
    if (string_buffer == NULL)
    {
        printf("error: malloc for string_buffer\n");
        return NULL;
    }

    printf("enter the artist's name: ");
    int name_input;
    while ((name_input = getchar()) != '\n' && name_input != EOF)
    {
        bytes_used++;

        while (1)
        {
            if (bytes_used > capacity - 1)
            {
                char *temp = realloc(string_buffer, (capacity * 2) * sizeof(char));
                if (temp == NULL)
                {
                    printf("error: realloc for temp\n");
                    free(string_buffer);
                    string_buffer = NULL;
                    return NULL;
                }
                capacity *= 2;
                string_buffer = temp;
            }
            else
            {
                break;
            }
        }

        string_buffer[index] = name_input;
        index++;
    }

    string_buffer[bytes_used] = '\0';
    return string_buffer;
}

struct Song *add_song(char *title_parameter, char *artist_parameter, float duration_parameter) {
    struct Song *new_song = malloc(sizeof(struct Song));
    if (new_song == NULL) {
        printf("error: malloc for new_song");
        return NULL;
    }

    if (title_parameter == NULL) {
        printf("error: get_song_name() returned NULL");
        return NULL;
    }

    if (artist_parameter == NULL) {
        printf("error: get_artist_name() returned NULL");
        return NULL;
    }

    new_song->song_title = title_parameter;
    new_song->artist_name = artist_parameter;
    new_song->song_duration = duration_parameter;
    new_song->prev = NULL;
    new_song->next = NULL;

    if (first_song == NULL) {
        first_song = new_song;
        return new_song;
    }

    struct Song *current_song = NULL;
    current_song = first_song;
    while (current_song->next != NULL) {
        current_song = current_song->next;
    }
    current_song->next = new_song;
    new_song->prev = current_song;

    last_song = new_song;

    return new_song;
}