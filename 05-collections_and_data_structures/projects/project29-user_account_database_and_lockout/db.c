#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define CAPACITY 3

struct User
{
    int id;
    int pin;
    int locked; // bool... 0 is no, 1 is yes
    int failed; // tally
};

int main()
{
    struct User users[CAPACITY];
    int counter = 0;

    // manually creating the users
    users[0].id = 1000;
    users[0].pin = 1234;
    users[0].locked = 0;
    users[0].failed = 0;
    counter++;

    users[1].id = 1001;
    users[1].pin = 5678;
    users[1].locked = 1;
    users[1].failed = 0;
    counter++;

    users[2].id = 1002;
    users[2].pin = 9121;
    users[2].locked = 0;
    users[2].failed = 0;
    counter++;

    /*take user input and check if the user ID exists*/
    char id_buffer[10];
    int is_valid = 1;   // bool
    int entered_id = 0; // to hold the converted value

    printf("enter your User ID: ");
    fgets(id_buffer, sizeof(id_buffer), stdin);
    id_buffer[strcspn(id_buffer, "\n")] = '\0';

    // validate the input
    if (strlen(id_buffer) == 0)
    {
        is_valid = 0;
    }

    for (int i_validate = 0; i_validate < strlen(id_buffer); i_validate++)
    {
        if (isdigit(id_buffer[i_validate]) == 0)
        { // if the char is not a digit
            is_valid = 0;
            break;
        }
    }

    // if it is valid, then convert... if not, then print error
    if (is_valid == 1)
    {
        entered_id = atoi(id_buffer);
    }
    else
    {
        printf("error occured...\n");
        return 1;
    }

    // check if the user ID exists in the database
    int id_found = 0;                                            // bool
    int found_index;                                             // to store the index of the found ID in the array
    for (int i_existsQM = 0; i_existsQM < counter; i_existsQM++) // QM = question mark
    {
        if (entered_id == users[i_existsQM].id)
        {
            id_found = 1;
            found_index = i_existsQM;
            break; // exit the loop once found
        }
    }

    if (id_found == 0) {
        printf("no user by that ID exists\n");
        return 1;
    }

    // if the ID is found AND is not locked, then ask for the PIN... if not then tell the user
    // the account is locked, then exit the program
    if (id_found == 1 && users[found_index].locked != 0)
    {
        // do something
    }
    else
    {
        printf("account is locked\n");
        return 1;
    }
    return 0;
}