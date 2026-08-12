#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define GRUNT 5
#define JACKAL 6
#define HUNTER 6

char *get_name() {
    int rand_choice = rand() % 3;
    char *name_to_return;
    switch (rand_choice)
    {
    case 0:
        name_to_return = malloc((GRUNT * sizeof(char)) + 1); //+1 for \0 
        if (name_to_return == NULL) {printf("error in malloc for 'name_to_return'\n"); return NULL;}
        memcpy(name_to_return, "grunt\0", GRUNT + 1);
        break;
    case 1:
        name_to_return = malloc((JACKAL * sizeof(char)) + 1); //+1 for \0 
        if (name_to_return == NULL) {printf("error in malloc for 'name_to_return'\n"); return NULL;}
        memcpy(name_to_return, "jackal\0", JACKAL + 1);
        break;
    case 2:
        name_to_return = malloc((HUNTER * sizeof(char)) + 1); //+1 for \0 
        if (name_to_return == NULL) {printf("error in malloc for 'name_to_return'\n"); return NULL;}
        memcpy(name_to_return, "hunter\0", HUNTER + 1);
        break;
    
    default:
        printf("something happened in the switch statement\n");
        break;
    }

    return name_to_return;
}

struct Enemy {
    char *name;
    int cordinate_x;
    int cordinate_y;
};

struct Enemy *spawn_enemy(char *name_parameter, int x_parameter, int y_parameter);

int main() {
    srand(time(NULL));
    
    return 0;
}