#include <stdio.h>
#include <stdlib.h>

int compare_asc(const void *a, const void *b)
{                          // the mem add of para a and para b
    int *int_a = (int *)a; // tell the compiler to treat this mem add as a int when interpreting
    int *int_b = (int *)b;


    return (*int_a - *int_b);
}

int compare_desc(const void *a, const void *b)
{
    int *int_a = (int *)a;
    int *int_b = (int *)b;

    return (*int_b - *int_a);
}

int main()
{
    int scores[] = {50, 10, 90, 20};
    int count = 4;
    // before sort:
    for (int i_before = 0; i_before < count; i_before++)
    {
        printf("Index: %d Value: %d\n", i_before, scores[i_before]);
    }

    // now time to sort (ascending)
    printf("\n");
    qsort(scores, 4, sizeof(int), compare_asc);
    for (int i_ascend = 0; i_ascend < count; i_ascend++)
    {
        printf("Index: %d Value: %d\n", i_ascend, scores[i_ascend]);
    }

    // now time to sort (descending)
    printf("\n");
    qsort(scores, 4, sizeof(int), compare_desc);
    for (int i_descend = 0; i_descend < count; i_descend++)
    {
        printf("Index: %d Value: %d\n", i_descend, scores[i_descend]);
    }

    return 0;
}