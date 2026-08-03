#include <stdio.h>
#include <stdlib.h>

#include "utils.h"
#include "utils.c"

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