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

//im assuming its a 16 x 16 grid... no need to overcomplicate rn
int pos_x() {
    int x = rand() % 15;
    return x;
}

int pos_y() {
    int y = rand() % 15;
    return y;
}

struct Enemy {
    char *name;
    int cordinate_x;
    int cordinate_y;
};

struct Enemy *spawn_enemy() {
    struct Enemy *created_enemy = malloc(sizeof(struct Enemy));
    if (created_enemy == NULL) {printf("error in malloc for created_enemy\n"); return NULL;}
    created_enemy->name = get_name();
    if (created_enemy->name == NULL) {printf("get_name returned null, freeing created_enemy\n"); return NULL;}
    created_enemy->cordinate_x = pos_x();
    created_enemy->cordinate_y = pos_y();

    return created_enemy;
}

int main() {
    srand(time(NULL));
    struct Enemy *enemies[3] = {spawn_enemy(), spawn_enemy(), spawn_enemy()};
    //print the details of each enemy
    for (int i = 0; i < 3; i++) {
        printf("\nName: %s\n", enemies[i]->name);
        printf("Pos X: %d\n", enemies[i]->cordinate_x);
        printf("Pos Y: %d\n", enemies[i]->cordinate_y);
    }

    //now free the memory
    for (int j = 0; j < 3; j++) {
        free(enemies[j]->name);
        free(enemies[j]);
        enemies[j] = NULL;
    }
}