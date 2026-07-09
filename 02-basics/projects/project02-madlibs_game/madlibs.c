/*
Author: fiberlabs
Date: 02nd June 2026
Purpose: I am Learning C
*/

#include <stdio.h>

int main() 
{
    char adjective[50];
    char noun[50]; //chose char[] because C does not have a native C type...
    char verb[50];
    int number1;
    char city_name[50];
    int number2;

    printf("enter a adjective: ");
    scanf("%s", adjective);

    printf("enter a noun: ");
    scanf("%s", noun);

    printf("enter a verb: ");
    scanf("%s", verb);

    printf("enter a number: ");
    scanf("%d", &number1);

    printf("enter a city name: ");
    scanf("%s", city_name);

    printf("enter another number: ");
    scanf("%d", &number2);

    printf("the %s %s decided to %s %d times.\neveryone in the %s was shocked.\n\"never in my %d years have i seen such a thing!\" said the mayor\n", adjective, noun, verb, number1, city_name, number2);

    return 0;
}