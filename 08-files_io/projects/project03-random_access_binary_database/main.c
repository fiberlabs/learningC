// main.c
#include <stdio.h>

#include "utils.h"

int main() {
    int user_input = print_menu();

    switch (user_input)
    {
    case 1:
        //ADD RECORD LOGIC
        break;

    case 2:

        //VIEW RECORD LOGIC
        break;
    case 3:

        //LIST ALL LOGIC
        break;
    case 4:
        //QUIT PROGRAM LOGIC
        break;

    default:
        break;
    }
    
    printf("you chose: %d\n", user_input);

    return 0;
}