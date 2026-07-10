#include <stdio.h>

int main()
{
    double num_1;
    double num_2;
    char operator;

    printf("enter the first number: ");
    scanf("%lf", &num_1);

    printf("enter the second number: ");
    scanf("%lf", &num_2);

    printf("enter the operator you want use (+, -, *, /): ");
    scanf(" %c", &operator);

    switch (operator)
    {
    case '+':
        printf("%.2lf + %.2lf = %.2lf\n", num_1, num_2, num_1 + num_2);
        break;

    case '-':
        printf("%.2lf - %.2lf = %.2lf\n", num_1, num_2, num_1 - num_2);
        break;

    case '*':
        printf("%.2lf * %.2lf = %.2lf\n", num_1, num_2, num_1 * num_2);
        break;

    case '/':
        if (num_2 == 0) {
            printf("Error: Division by zero\n");
            break;
        }
        else {
            printf("%.2lf / %.2lf = %.2lf\n", num_1, num_2, num_1 / num_2);
            break;
        }
    
    default:
        printf("invalid input, please try again\n");
        break;
    }

    return 0;
}