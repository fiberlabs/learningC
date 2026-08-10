#include <stdio.h>
#include "utils.h"

int main() {
    struct Details my_contact = fill_details();
    
    printf("\n--- Contact Summary ---\n");
    printf("Phone: %s\n", my_contact.phone_number);
    printf("Email: %s\n", my_contact.email_address);

    // TODO: Remember to free memory later!
    return 0;
}