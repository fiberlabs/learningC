// ⭐ Project 1 — The "Exact Fit" Array
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("not enough arguements to run the program... bye\n");
        return 1;
    }

    int size = atoi(argv[1]); //convert the second element in the array

    int *ptr = malloc(size * sizeof(int)); //so ptr right now holds the mem add of mem in the heap of a specific size
    //we multiply because when you do for example int arr[5]; that is actually 20 bytes in mem because each index is 4 bytes

    if (ptr == NULL) {
        printf("malloc returned NULL... exiting\n");
        return 1;
    }

    int ptr_count = 0;

    //so ptr is the array now... because array and ptr look the same in mem... well technically arrays are just what
    //ptr is... which is a mem add that stores some data... point is they are identical
    //lets fill it now
    for (int i = 0; i < size; i++) {
        ptr[i] = i * 10; //will store 10, 20, 30,... etc.
        ptr_count++;
    }

    //print the contents
    for (int i = 0; i < ptr_count; i++) {
        printf("%d\n", ptr[i]);
    }

    //now lets free the mem
    free(ptr);
    ptr = NULL;

    return 0;
}