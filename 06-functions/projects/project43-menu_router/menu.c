#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

int main() {
    int (*operations[3])(int, int) = {add, sub, mul};

    int ui_1;
    int ui_2;
    int ui_op;
    printf("enter number 1: ");
    scanf("%d", &ui_1);

    printf("enter number 2: ");
    scanf("%d", &ui_2);

    printf("enter an operator (0 for add, 1 for sub, 2 for mul): ");
    scanf("%d", &ui_op);

    int result = operations[ui_op](ui_1, ui_2);
    printf("%d\n", result);

    return 0;
}