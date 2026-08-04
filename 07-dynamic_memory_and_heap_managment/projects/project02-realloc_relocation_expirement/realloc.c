#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr_a = malloc(2 * sizeof(int));

    if (ptr_a == NULL)
    {
        printf("error in malloc ptr_a\n");
        return 1;
    }
    else
    {
        ptr_a[0] = 1;
        ptr_a[1] = 2;

        printf("memory address of ptr_a: %p\nindex 0: %d\nindex 1: %d\n", (void *)ptr_a, ptr_a[0], ptr_a[1]);
    }

    int *ptr_b = malloc(2 * sizeof(int));
    if (ptr_b == NULL)
    {
        printf("error in malloc ptr_b\n");
        return 1;
    }
    else
    {
        ptr_b[0] = 99;
        ptr_b[1] = 100;

        printf("memory address of ptr_b: %p\nindex 0: %d\nindex 1: %d\n", (void *)ptr_b, ptr_b[0], ptr_b[1]);
    }

    int *temp = realloc(ptr_a, 262144 * sizeof(int)); //gimme 1 mb to store a bunch of ints
    if (temp == NULL) {
        printf("error in realloc\n");
        free(ptr_a);
        ptr_a = NULL;
        return 1;
    }
    else {
        ptr_a = temp;
        /*
        ok we can free temp now because unlike the prev assignment... ptr_a and temp are not pointing to
        the same mem address due to ptr_b blocking the expansion
        */
        temp = NULL; 
        int count = 100; //assume it stores 100 ints

        //print the mem add
        printf("the mem add of ptr_a after realloc: %p\n", (void *)ptr_a);

        for (int i = 0; i < count; i++) { //fill up the memadd and print the vals
            ptr_a[i] = i * 1;
            printf("Index: %d Value: %d\n", i, ptr_a[i]);
        }

        printf("this could go on forever...\n");

        //free the allocated memory now
        free(ptr_a);
        ptr_a = NULL;
        free(ptr_b);
        ptr_b = NULL;
    }


    return 0;
}