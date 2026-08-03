//bank.c
#include <stdio.h>
#include "utils.h"

int main() {

    struct Account user = initialize_user(100);

    void (*pipeline[])(struct Account *account_parameter) = {
        display_balance,
        deposit_100,
        display_balance,
        withdraw_50,
        display_balance,
        NULL
    };

    for (int i = 0; pipeline[i] != NULL; i++) {
        (*pipeline[i])(&user);
    }

    return 0;
}