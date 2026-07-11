#include <stdio.h>
#include <string.h>

int main()
{
    int arr1[5] = {10, 20, 30, 40, 50};
    int arr2[5];

    memcpy(arr2, arr1, sizeof(arr1));

    for (int i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
    {
        printf("byte %d value: %d\n", i, arr2[i]);
    }

    if (memcmp(arr1, arr2, sizeof(arr1)) == 0)
    {
        printf("both arrays are the same\n");
    }
    else
    {
        printf("both arrays are different\n");
    }

    memset(arr1, 0, sizeof(arr1));
    for (int i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
    {
        printf("byte %d value: %d\n", i, arr1[i]);
    }

    char text[] = "HELLO";
    memmove(text, text + 1, strlen(text) + 1);
    printf("%s\n", text);
}