#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); 

    int secret_number = 1 + rand() % 10;
    int user_input;

    // printf("the secret number is: %d\n", secret_number); //just to check


    while (user_input != secret_number)
    {

        printf("guess the secret number (bw 1-10): ");
        scanf("%d", &user_input);

        if (user_input < secret_number) {
            printf("wrong... try a bigger number\n");
            continue;
        }
        else if (user_input > secret_number) {
            printf("wrong... try a smaller number\n");
            continue;
        }
        else {
            printf("you won!\n");
            break;
        }

    }

    return 0;
}

/* OLD CODE:
#include <stdio.h>

int main() 
{
    int secret = 7;

    int user_guess;
    printf("guess the secret number (it's between 1 and 10): ");
    scanf("%d", &user_guess);

    if (user_guess < secret) {
        printf("wrong... try a bigger number\n");
    }
    else if (user_guess > secret) {
        printf("wrong... try a smaller number\n");
    }
    else {
        printf("you won!\n");
    }
    return 0;

}

*/