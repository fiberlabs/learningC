#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Quest {
    char *quest_name;
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

char *get_name() {
    int bytes_used = 0;
    int byte_index = 0;

    int bytes_capacity = 8;
    char *name_buffer = malloc(bytes_capacity * sizeof(char));
    if (name_buffer == NULL) {printf("error: malloc name_buffer"); return NULL;}

    printf("enter quest name: ");
    int name_input;
    while ((name_input = getchar()) != '\n' && name_input != EOF)
    {
        bytes_used++;

        if (bytes_used > bytes_capacity - 1) {
            char *temp = realloc(name_buffer, (bytes_capacity * 2) * sizeof(char));
            if (temp == NULL) {printf("error: realloc temp"); free(name_buffer); name_buffer = NULL; return NULL;}
            name_buffer = temp;
            free(temp); //cuz we no longer need it
        }

        bytes_capacity *= 2;
        name_buffer[byte_index] = name_input;
        byte_index++;
    }
    
    name_buffer[bytes_used] = '\0'; //adding the null byte

    return name_buffer;
}

int main() {
    printf("entered name: %s\n", get_name());

    return 0;
}