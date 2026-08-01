#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void attack() {printf("enemy attacks!\n");};
void defend() {printf("enemy defends!\n");};
void flee() {printf("enemy flees!\n");};

int main() {
    srand(time(NULL));

    void (*actions[])() = {attack, defend, flee};

    for (int i = 0; i < 5; i++) {
        actions[rand() % 3]();
    }

    return 0;
}