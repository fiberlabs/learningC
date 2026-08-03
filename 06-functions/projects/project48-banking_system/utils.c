//utils.c

#include <stdio.h>
#include <string.h>

#include "utils.h"

struct Account initialize_user(int id) {
    struct Account user;
    user.id = id;
    user.balance = 1000.00;

    return user;
};

void deposit_amount(struct Account *account_parameter, float amount) {
    printf("\nDEPOSITING %.2lf in Account ID: %d\n", amount, account_parameter->id);
    account_parameter->balance += amount;
}

void deposit_100(struct Account *account_parameter) {
    deposit_amount(account_parameter, 100.00);
}


void withdraw_amount(struct Account *account_parameter, float amount) {
    if (account_parameter->balance - amount >= 0) {
        printf("\nWITHDRAWING %.2lf in Account ID: %d\n", amount, account_parameter->id);
        account_parameter->balance -= amount;
    }
    else {
        printf("insufficient funds to process this transaction\n");
    }
}

void withdraw_50(struct Account *account_parameter) {
    withdraw_amount(account_parameter, 50.00);
}

void display_balance(struct Account *account_parameter) {
    printf("ID: %d\nYour Balance: %.2lf\n", account_parameter->id, account_parameter->balance);
}