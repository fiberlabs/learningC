#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define CAPACITY 3

enum AccountStatus
{
    ACTIVE,
    LOCKED
};

struct User
{
    char username[100];
    int pin;
    enum AccountStatus status;
    int failed_logins; // tally
};

int main()
{
    struct User users[CAPACITY];
    int count = 0;

    // now manually creating the users
    strcpy(users[0].username, "fiberlabs");
    users[0].pin = 1234;
    users[0].status = ACTIVE;
    users[0].failed_logins = 0;
    count++;

    strcpy(users[1].username, "johndoe");
    users[1].pin = 1000;
    users[1].status = LOCKED;
    users[1].failed_logins = 0;
    count++;

    strcpy(users[2].username, "janedoe");
    users[2].pin = 2000;
    users[2].status = ACTIVE;
    users[2].failed_logins = 0;
    count++;

    /*ask the user to enter their username*/
    char username_buffer[100];
    int user_exists = 0; // bool (1 is yes, 0 is no)
    int valid_input = 0;

    while (1)
    {

        printf("enter your username: ");
        fgets(username_buffer, sizeof(username_buffer), stdin);
        username_buffer[strcspn(username_buffer, "\n")] = '\0';

        // validate input (BASIC STUFF)
        if (strlen(username_buffer) == 0)
        {
            valid_input = 0;
            printf("you did not enter anything, try again");
            continue;
        }
        else
        {
            valid_input = 1;
        }

        /*now check if the username exists*/
        int id_found = 0; // bool
        int found_index;  // to store the index of the found ID from the array

        if (valid_input)
        {
            for (int username_i = 0; username_i < count; username_i++)
            {
                if (strcmp(username_buffer, users[username_i].username) == 0)
                {
                    id_found = 1;
                    found_index = username_i;
                    break; // exit the for loop because we have found the user
                }
            }

            if (!id_found) {
                printf("no user by that username exists.\n");
                continue;
            }
        }

        /*if the account is not locked, then ask for the PIN code*/
        int entered_pin;
        int pin_correct = 0; // bool
        char pin_buffer[10];

        if (users[found_index].status == LOCKED)
        {
            printf("account is locked\n");
            return 1;
        }
        else
        {
            while (users[found_index].failed_logins < 3)
            {
                int valid_pin_input = 1;

                printf("enter your PIN code: ");
                fgets(pin_buffer, sizeof(pin_buffer), stdin);
                pin_buffer[strcspn(pin_buffer, "\n")] = '\0';

                // validate input
                if (strlen(pin_buffer) == 0)
                {
                    valid_pin_input = 0;
                    printf("invalid input, try again\n");
                    continue;
                }

                entered_pin = atoi(pin_buffer);

                // compare them now
                if (entered_pin == users[found_index].pin)
                {
                    users[found_index].failed_logins = 0; // reset tally
                    pin_correct = 1;
                    break;
                }
                else
                {
                    users[found_index].failed_logins++;
                    printf("WRONG PIN... %d attempt(s) remaining\n", 3 - users[found_index].failed_logins);
                }

                if (users[found_index].failed_logins >= 3)
                {
                    users[found_index].status = LOCKED;
                    printf("too many failed attempts, account is now locked\n");
                    return 1;
                }
            }

            if (pin_correct)
            {
                printf("welcome back %s!\n", users[found_index].username);
                break; //will exit the while(1) loop
            }
        }
    }

    return 0;
}