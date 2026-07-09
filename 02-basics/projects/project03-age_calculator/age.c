#include <stdio.h>

int main()
{
    int current_year;
    int birth_year;

    printf("what year is it right now?: ");
    scanf("%d", &current_year);

    printf("what year were you born in?: ");
    scanf("%d", &birth_year);

    int current_age = current_year - birth_year;

    long long int total_heartbeats = (long long int)current_age * 365.25 * 24 * 60 * 80;

    printf("your heart has beaten approx. %lld times so far!", total_heartbeats);

    return 0;
}