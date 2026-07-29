#include <stdio.h>

void show_stack(int n) {
    int local = 42;
    printf("local var address: %p\n", (void*)&local);
    printf("parameter var address: %p\n", (void*)&n);
}

void middleman() {
    show_stack(20);
}

int main()
{
    printf("show_stack from main:\n");
    show_stack(10);


    printf("\n");

    printf("nested show stack:\n");
    middleman();

    return 0;
}; 
