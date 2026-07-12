#include <stdio.h>
#include <string.h>

int main()
{
    //part 1: integer arrays
    int numbers1[5] = {1, 2, 3, 4, 5};
    int numbers2[5];

    memcpy(numbers2, numbers1, sizeof(numbers1));

    printf("\nInteger Array Number 1\n");
    for (size_t i = 0; i < sizeof(numbers1) / sizeof(numbers1[0]); i++)
    {
        printf("value %zu: %d\n", i, numbers1[i]);
    }

    printf("\nInteger Array Number 2\n");
    for (size_t i = 0; i < sizeof(numbers2) / sizeof(numbers2[0]); i++)
    {
        printf("value %zu: %d\n", i, numbers2[i]);
    }

    if (memcmp(numbers1, numbers2, sizeof(numbers1)) != 0) {
        printf("they are not identitcal\n");
    }
    else {
        printf("they are identical\n");
    }

    //part 2: reset memory
    memset(numbers2, 0, sizeof(numbers2));

    printf("\nReset Memory Array 2\n");
    for (size_t i = 0; i < sizeof(numbers2) / sizeof(numbers2[0]); i++)
    {
        printf("value %zu: %d\n", i, numbers2[i]);
    }

    //part 3: character array
    char text[] = "SYSTEMS";
    printf("orignal: %s\n", text);

    memmove(text, text + 1, sizeof(text) - 1);
    printf("modified: %s\n", text);


    return 0;
}