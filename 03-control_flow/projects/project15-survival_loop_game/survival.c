#include <stdio.h>

int main() 
{
    int energy = 10;
    int user_input;

    while (energy > 0) 
    {
        //print menu
        printf("\nyour current energy level:\t%d\n", energy);
        printf("\n----MENU----\n1.Explore (-2 Energy)\n2.Rest (+1 Energy)\n3.Quit\n");
        //take user input
        printf("choose an option (e.g. 1, 2, or 3): ");
        scanf("%d", &user_input);

        //switch condition
        switch (user_input)
        {
            //explore
        case 1:
            printf("exploring...\n");
            energy -= 2;
            break;
            //rest
        case 2:
            printf("resting...\n");
            energy++;
            break;
            //quit
        case 3:
            printf("goodbye :)\n");
            break;
        default:
            printf("wrong input, try again");
            break;
        }

        if (user_input == 3) 
        {
            break;
        }

        if (energy <= 0) 
        {
            printf("you ran out of energy... rest and come back later :)\n");
        }

    }

    return 0;
}