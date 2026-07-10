#include <stdio.h>
#include <unistd.h>

int main() 
{
    int user_input;
    printf("enter a integer value (e.g. 1, 2,... 100, etc.): ");
    scanf("%d", &user_input);

    for (int i = user_input; i >= 0; i--)
    {
        printf("%d\n", i);
        sleep(1);
    }

    printf("BLAST OFF!\n"); //this will run once the for loop ends
    
    return 0;
}