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

    users[1].id = 1001;
    users[1].pin = 5678;
    users[1].locked = 1;
    users[1].failed = 0;

    users[2].id = 1002;
    users[2].pin = 9121;
    users[2].locked = 0;
    users[2].failed = 0;

    /*take user input and check if the user ID exists*/
    char id_buffer[10];
    int is_valid = 1; // bool
    int stored_id = 0; //to hold the converted value

    printf("enter your User ID: ");
    fgets(id_buffer, sizeof(id_buffer), stdin);
    id_buffer[strcspn(id_buffer, "\n")] = '\0';

    // validate the input
    if (strlen(id_buffer) == 0)
    {
        is_valid = 0;
    }

    for (int i = 0; i < strlen(id_buffer); i++)
    {
        if (isdigit(id_buffer[i]) == 0)
        { // if the char is not a digit
            is_valid = 0;
            break;
        }
    }

    //if it is valid, then convert... if not, then print error
    if (is_valid == 1)
    {
        stored_id = atoi(id_buffer);
        printf("you entered %d\n", stored_id);
    }
    else{
        printf("error, thats not a valid arguement\n");
    }

    return 0;
}