#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test_utils.h"

int email_menu()
{
    int emenu_input = 0;
    printf("---available email providers---:\n1-\t@gmail.com\n2-\t@hotmail.com\n3-\t@protonmail.com\n");

    while (emenu_input != 1 && emenu_input != 2 && emenu_input != 3)
    {
        printf("choose an option (1, 2, or 3): ");
        if (scanf("%d", &emenu_input) == 1)
        {
            // clear input buffer
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
        }

        if (emenu_input != 1 && emenu_input != 2 && emenu_input != 3)
        {
            printf("must choose between the listed email providers\n");
        }
    }

    return emenu_input;
}

char *get_domain_string(enum AllowedEmailServices service)
{
    switch (service)
    {
    case GMAIL:
        return "@gmail.com";
    case HOTMAIL:
        return "@hotmail.com";
    case PROTON:
        return "@protonmail.com";
    default:
        return "@unknown.com";
    }
}

char *get_username(struct EmailDetails *username_parameter)
{
    username_parameter->bytes_used_for_username = 0;

    int username_capacity = 8;
    username_parameter->username_storage = malloc(username_capacity * sizeof(char));
    if (username_parameter->username_storage == NULL)
    {
        printf("error in username_storage malloc\n");
        return NULL;
    }

    printf("enter your username (the part that comes before '@' in a email): ");
    int username_input;
    int index = 0;
    while ((username_input = getchar()) != '\n' && username_input != EOF)
    {
        username_parameter->bytes_used_for_username++;

        while (1)
        {
            if (username_parameter->bytes_used_for_username > username_capacity - 1)
            {
                char *temp = realloc(username_parameter->username_storage, (username_capacity * 2) * sizeof(char));
                if (temp == NULL) {
                    printf("error in reallocating username_storage\n");
                    free(username_parameter->username_storage);
                    username_parameter->username_storage = NULL;
                    return NULL;
                }

                username_capacity *= 2;
                username_parameter->username_storage = temp;
            }
            else
            {
                break;
            }
        }

        username_parameter->username_storage[index] = username_input;
        index++;
    }

    username_parameter->username_storage[index] = '\0';

    return username_parameter->username_storage;
}

char *get_domain(struct EmailDetails *email_parameter) {
    return email_parameter->domain_storage = get_domain_string(email_parameter->service = (enum AllowedEmailServices)email_menu());
}

char *fill_phone_number(struct Details *created_struct_parameter)
{
    int number_of_bytes = 0;
    int index = 0;

    created_struct_parameter->phone_number = malloc((13 + 1) * sizeof(char));
    if (created_struct_parameter->phone_number == NULL) {
        printf("error during malloc for phone number, exiting\n");
        return NULL;
    }

    printf("enter the 13 digit phone number: ");
    int phone_input;
    while ((phone_input = getchar()) != '\n' && phone_input != EOF)
    {
        if (number_of_bytes < 13) {
            number_of_bytes++;
            created_struct_parameter->phone_number[index] = phone_input;
            index++;
        } 
        else {
            printf("exceeded 13 digits, exiting\n");
            while ((phone_input = getchar()) != '\n' && phone_input != EOF);
            break;
        }
    }

    created_struct_parameter->phone_number[number_of_bytes] = '\0';

    return created_struct_parameter->phone_number;
}

char *fill_email_address()
{
    struct EmailDetails email_details;
    email_details.username_storage = get_username(&email_details);
    email_details.domain_storage = get_domain(&email_details);

    email_details.full_email = malloc((strlen(email_details.username_storage) + strlen(email_details.domain_storage) + 1) * sizeof(char));
    if (email_details.full_email == NULL) {
        printf("error in malloc for the full email\n");
        return NULL;
    }

    snprintf(email_details.full_email, strlen(email_details.username_storage) + strlen(email_details.domain_storage) + 1, "%s%s", email_details.username_storage, email_details.domain_storage);

    return email_details.full_email;
}

struct Details fill_details()
{
    struct Details contact_details;

    contact_details.phone_number = fill_phone_number(&contact_details);
    contact_details.email_address = fill_email_address(); // Fixed: no arguments passed

    return contact_details;
}