#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Quest {
    char *title_name;
    struct Quest *next;
};

int menu_input() {
    int user_input = 0;
    printf("Choose an option:\n1. Add quest\n2. Print quests\n3. Exit program\n> ");
    while (user_input != 1 && user_input != 2 && user_input != 3)
    {
        if (scanf("%d", &user_input) == 1) {
            //clear input buffer
            int c;
            while((c = getchar()) != '\n' && c != EOF);
        }


        if ((user_input != 1 && user_input != 2 && user_input != 3)) {
            printf("invalid input, try again\n> ");
        }
    }

    return user_input;
}

int main() {


    return 0;
}