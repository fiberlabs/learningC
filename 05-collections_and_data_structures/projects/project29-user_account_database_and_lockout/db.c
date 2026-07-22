#include <stdio.h>

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

    // take user input and check if the user ID exists
    int find_user_input;
    int user_found = 0;
    int the_user_id = 0;
    int find_user_fail_tally = 0; // if this reaches 3, exit the program...

    while (1)
    {
        printf("enter your ID: ");
        scanf("%d", &find_user_input);

        if (find_user_input == users[0].id || find_user_input == users[1].id || find_user_input == users[2].id)
        {
            user_found = 1;
            the_user_id = find_user_input;
            break;
        }
        else
        {
            printf("user not found, try again...\n");
            find_user_fail_tally++;
        }
        
        if (find_user_fail_tally >= 3)
        {
            printf("too many failed attempts, try again later...\n");
            break;
        }
    }

    if (user_found) {
        printf("you are user %d\n", the_user_id);
    }

    return 0;
}