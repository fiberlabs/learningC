#include <stdio.h>

int main()
{
    // declare and init needed variables
    int attempts = 3;
    int is_authenticated = 0;
    int user_password = 1234;
    int password_input;
    int menu_input;
    double balance = 1000;
    char currency_type = '$';
    double deposit_input;
    double withdraw_input;
    int exit_program = 0; //bool

    // code for user auth
    do
    {
        // the password is 1234
        printf("enter your password: ");
        scanf("%d", &password_input);

        if (password_input != user_password)
        {
            printf("wrong password, please try again...\n");
            attempts--;
        }
        else
        {
            printf("logging you in...\n");
            is_authenticated = 1;
        }

        if (attempts <= 0)
        {
            printf("too many wrong attempts, try again later\n");
            return 1;
        }

    } while (is_authenticated == 0);

    // display menu
    while (1)
    {
        printf("\n==== ATM ===\n");
        printf("1. Check Balance\n2. Deposit\n3. Withdraw\n4. Exit\n");

        printf("choose an option: ");
        scanf("%d", &menu_input);

        switch (menu_input)
        {
            //view balance
        case 1:
            printf("your current balance is:\t%c%.2lf\n", currency_type, balance);
            break;
            //deposit money
        case 2:
            printf("how much money would you like to deposit?: ");
            scanf("%lf", &deposit_input);
            balance += deposit_input;
            printf("your new balance is:\t%c%.2lf\n", currency_type, balance);
            break;
            //withdraw money
        case 3:
            printf("current balance is:\t%c%.2lf\n", currency_type, balance);
            printf("how much do you want to withdraw from the account?: ");
            scanf("%lf", &withdraw_input);

            if (withdraw_input > balance)
            {
                printf("error... you do not have sufficient funds to process this transaction\n");
                return 1;
            }
            else
            {
                balance -= withdraw_input;
                printf("remaining balance is:\t%c%.2lf\n", currency_type, balance);
            }

            break;
            //exit program
        case 4:
            exit_program = 1;
            printf("goodbye!\n");
            break;

        default:
            printf("invalid input, please try again");
            break;
        }

        if (exit_program == 1) {
            break;
        }
    }

    return 0;
}