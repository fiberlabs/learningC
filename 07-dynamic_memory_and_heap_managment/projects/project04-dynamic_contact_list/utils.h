struct Details {
    char *phone_number;
    char *email_address;
};

struct PhoneNumberDetails {
    int number_of_bytes;
};

struct Details fill_details();

char *fill_phone_number(struct Details *created_struct_parameter);