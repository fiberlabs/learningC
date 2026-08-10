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

char *get_phone_number()
{
    int capacity = 16; //because phone numbers are usually bigger
    char *phone_number_buffer = malloc(capacity * sizeof(char));

    printf("enter contact's phone number: ");
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
                char *temp = realloc(phone_number_buffer, (capacity * 2) * sizeof(char));
                if (temp == NULL) {
                    printf("error in realloc for name_buffer\n");
                    free(phone_number_buffer);
                    phone_number_buffer = NULL;
                    return NULL;
                }

                capacity *= 2;
                phone_number_buffer = temp;
            }
            else
            {
                break;
            }
        }

        phone_number_buffer[index] = user_input;
        index++;
    }

    phone_number_buffer[bytes_used] = '\0';

    return phone_number_buffer;
}

char *get_email_address()
{
    int capacity = 16; //because phone numbers are usually bigger
    char *email_address_buffer = malloc(capacity * sizeof(char));

    printf("enter contact's email address: ");
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
                char *temp = realloc(email_address_buffer, (capacity * 2) * sizeof(char));
                if (temp == NULL) {
                    printf("error in realloc for name_buffer\n");
                    free(email_address_buffer);
                    email_address_buffer = NULL;
                    return NULL;
                }

                capacity *= 2;
                email_address_buffer = temp;
            }
            else
            {
                break;
            }
        }

        email_address_buffer[index] = user_input;
        index++;
    }

    email_address_buffer[bytes_used] = '\0';

    return email_address_buffer;
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
        printf("[DEBUG] contact %d name: %s\n", i, contacts[i][0]);
        //fill in the phone_number
        contacts[i][1] = get_phone_number();
        printf("[DEBUG] contact %d phone number: %s\n", i, contacts[i][1]);
        //fill in the phone_number
        contacts[i][2] = get_email_address();
        printf("[DEBUG] contact %d email address: %s\n", i, contacts[i][2]);
    }

    return 0;
}