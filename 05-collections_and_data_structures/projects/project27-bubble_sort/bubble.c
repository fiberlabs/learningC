#include <stdio.h>

#define CAP 5

int main()
{
    int arr[CAP] = {5, 1, 4, 2, 8};
    int count = 5;

    for (int outer = 0; outer < count - 1; outer++)
    {
    for (int i = 0; i < count; i++)
    {
        printf("SLOT %d:\t%d\n", i, arr[i]);
    }

    for (int i = 0; i < count - 1 - outer; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            int temp = arr[i + 1];
            arr[i + 1] = arr[i];
            arr[i] = temp;
        }

        // i want to see the working thats why im doing this
        printf("\n");

        for (int i = 0; i < count; i++)
        {
            printf("SLOT %d:\t%d\n", i, arr[i]);
        }
    }
}

    return 0;
}
