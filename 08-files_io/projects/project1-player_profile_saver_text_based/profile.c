#include <stdio.h>
#include <stdlib.h>

struct Profile
{
    char *name;
    int hp;
    int level;
};

char *get_name()
{
    int bytes_used = 0;
    int byte_index = 0;

    int capacity = 8;
    char *name_buffer = malloc(capacity * sizeof(char));
    if (name_buffer == NULL)
    {
        perror("malloc for name_buffer returned NULL");
        return NULL;
    }

    printf("enter the profile's name: ");
    int user_input;
    while ((user_input = getchar()) != '\n' && user_input != EOF)
    {
        bytes_used++;

        while (1)
        {
            if (bytes_used > capacity - 1)
            {
                char *temp = realloc(name_buffer, (capacity * 2) * sizeof(char));
                if (temp == NULL)
                {
                    perror("realloc for temp returned NULL");
                    free(name_buffer);
                    name_buffer = NULL;
                    return NULL;
                }

                capacity *= 2;
                name_buffer = temp;
            }
            else
            {
                break;
            }
        }

        name_buffer[byte_index] = user_input;
        byte_index++;
    }

    name_buffer[bytes_used] = '\0';

    return name_buffer;
}

int get_health()
{
    int x = 0;
    printf("what is the profile's health?: ");
    if (scanf("%d", &x) == 1)
    {
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;
    }

    return x;
}

int get_level()
{
    int x = 0;
    printf("what is the profile's level?: ");
    if (scanf("%d", &x) == 1)
    {
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;
    }

    return x;
}

struct Profile *add_profile(char *name_parameter, int health_parameter, int level_parameter)
{
    if (name_parameter == NULL)
    {
        perror("name_parameter was NULL, exiting function");
        return NULL; // dont allocate memory for created profile
    }

    struct Profile *created_profile = malloc(sizeof(struct Profile));
    if (created_profile == NULL)
    {
        perror("malloc for created_profile returned NULL");
        return NULL;
    }

    created_profile->name = name_parameter;
    created_profile->hp = health_parameter;
    created_profile->level = level_parameter;

    return created_profile;
}

int main()
{
    char *name = get_name();

    if (name == NULL) {
        perror("name (for 'char *name_parameter') is NULL");
        exit(1);
    }

    int hp = get_health();
    int level = get_level();
    struct Profile *profile1 = add_profile(name, hp, level);

    FILE *fp = NULL;
    fp = fopen("profiles.txt", "ab");
    if (fp == NULL)
    {
        perror("fopen() returned NULL");
        free(profile1->name);
        profile1->name = NULL;
        free(profile1);
        profile1 = NULL;
        exit(1);
    }

    fprintf(fp, "Name: \t%s\n", profile1->name);
    fprintf(fp, "HP:   \t%d\n", profile1->hp);
    fprintf(fp, "Level:\t%d\n", profile1->level);

    if (fclose(fp) != 0)
    {
        perror("fclose() failed");
        free(profile1->name);
        profile1->name = NULL;
        free(profile1);
        profile1 = NULL;
        exit(1);
    }

    free(profile1->name);
    profile1->name = NULL;
    free(profile1);
    profile1 = NULL;

    printf("Profile added successfully\n");

    return 0;
}