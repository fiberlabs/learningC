#include <stdio.h>

int main()
{
    double fahrenhiet_input;
    printf("enter the temprature (in F): ");
    scanf("%lf", &fahrenhiet_input);

    double celsius_temprature = (fahrenhiet_input - 32) * (5.0 / 9.0);

    printf("%lf F in celsius is %.2lf C\n", fahrenhiet_input, celsius_temprature);

    double celsius_input;
    printf("enter the temprature (in C): ");
    scanf("%lf", &celsius_input);

    double fahrenhiet_temprature = (celsius_input * (9.0/5.0)) + 32;

    printf("%lf C in fahrenhiet is %.2lf F\n", celsius_input, fahrenhiet_temprature);

    return 0;
}