#include <stdio.h>

#define CAPACITY 3

struct User
{
    int id;
    int pin;
    int locked; //bool
    int failures; //tally
};


int main()
{
    struct User users[CAPACITY];
    int count = 0;

    //manually creating users
    users[0].id = 100;
    users[0].pin = 1234;
    users[0].locked = 0;
    users[0].failures = 0;
    count++;

    users[0].id = 101;
    users[0].pin = 5678;
    users[0].locked = 0;
    users[0].failures = 0;
    count++;

    users[0].id = 102;
    users[0].pin = 1011;
    users[0].locked = 0;
    users[0].failures = 0;
    count++;

    //ask the user for their ID
    int user_input;
    printf("enter your user id: ");
    scanf("%d", &user_input);

    //see if ID is in the array
    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (users[i].id == user_input)
        {
            found = 1;
            break;
        }
    }

    if (found == 0) { //if user ID was not found
        printf("no existing user by that ID...\n");
    }
    else { //if the user id was found now do this

    }


    return 0;
}