//utils.h

struct Account {
    int id;
    float balance;
};

void deposit_amount(struct Account *account_parameter, float amount);
void withdraw_amount(struct Account *account_paramer, float amount);
void display_balance(struct Account *account_parameter);
void deposit_100(struct Account *account_parameter);
void withdraw_50(struct Account *account_parameter);
struct Account initialize_user(int id);