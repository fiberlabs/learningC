#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int how_many_contacts(int *number_of_contacts_para)
{
    int user_input = 0;
    while (user_input <= 0)
    {
        printf("how many contacts do you want to add?: ");
        if (scanf("%d", &user_input) == 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

    }

    *number_of_contacts_para = user_input;
    return *number_of_contacts_para;
}

char *get_contact_name()
{
    int capacity = 8;
    char *name_buffer = malloc(capacity * sizeof(char));

    printf("enter contact's name: ");
    int bytes_used = 0;
    int index = 0;
    int user_input;
    while ((user_input = getchar()) != '\n' && user_input != EOF)
    {
        bytes_used++;

        while (1)
        {
            if (bytes_used >= capacity - 1)
            {
                char *temp = realloc(name_buffer, (capacity * 2) * sizeof(char));
                if (temp == NULL) {
                    printf("error in realloc for name_buffer\n");
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

        name_buffer[index] = user_input;
        index++;
    }

    name_buffer[bytes_used] = '\0';

    return name_buffer;
}

int main()
{
    int number_of_contacts = how_many_contacts(&number_of_contacts);

    char ***contacts = malloc(number_of_contacts * sizeof(char **));
    if (contacts == NULL)
    {
        printf("error in malloc for 'contacts'\n");
        return 1;
    }

    for (int i = 0; i < number_of_contacts; i++)
    {
        contacts[i] = malloc(3 * sizeof(char *));
        // fill in the name
        contacts[i][0] = get_contact_name();
        printf("contact %d name: %s\n", i, contacts[i][0]);
    }

    return 0;
}