#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check_login(int entered_pin){
    static int attempts = 0;
    int pin_code = 1234;

    if (entered_pin == pin_code) {
        return 1;
    }

    attempts++;

    if (attempts >= 3) {
        return -1;
    }

    return 0;
}

int main()
{
    int entered_pin;
    int login_result;
    char pin_buffer[10];

    while (1)
    {
        printf("enter your PIN: ");
        fgets(pin_buffer, sizeof(pin_buffer), stdin);
        pin_buffer[strcspn(pin_buffer, "\n")] = '\0';

        entered_pin = atoi(pin_buffer);
        login_result = check_login(entered_pin);

        if (login_result == -1) {
            printf("too many attempts\n");
            return 1;
        }
        else if (login_result == 0) {
            printf("invalid PIN code, try again\n");
            continue;
        }
        else {
            printf("welcome back!\n");
            break; //exit the while (1) loopS
        }
    }

    return 0;
}