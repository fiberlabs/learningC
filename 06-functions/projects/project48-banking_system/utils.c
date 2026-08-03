#include <stdio.h>
#include <string.h>

enum SignedInStatus{
    SUCCESSFULL,
    NOT_SUCCESSFULL
};

struct Account {
    int id;
    float balance;
    char pin[5];
    enum SignedInStatus status;
};

struct Account initialize_user(struct Account) {
    struct Account user;
    user.id = 100;
    strcpy(user.pin, "1234");
    user.balance = 1000.00;
}

//create a function for a user login... return type int and use the enum
int something() {
    
}

void deposit_amount(struct Account *account_parameter, float amount) {
    printf("DEPOSITING %.2lf in Account ID: %d\n", amount, account_parameter->id);
    account_parameter->balance += amount;
}


void withdraw_amount(struct Account *account_parameter, float amount) {
    if (account_parameter->balance - amount >= 0) {
        account_parameter->balance -= amount;
        display_balance(account_parameter);
    }
    else {
        printf("insufficient funds to process this transaction\n");
    }
}

void display_balance(struct Account *account_parameter) {
    printf("ID: %d\nYour Balance: %.2lf\n", account_parameter->id, account_parameter->balance);
}