#ifndef UTILS_H
#define UTILS_H

struct Details {
    char *phone_number;
    char *email_address;
};

enum AllowedEmailServices
{
    GMAIL = 1,
    HOTMAIL,
    PROTON
};

struct EmailDetails
{
    int bytes_used_for_username;
    char *username_storage;
    char *domain_storage;
    enum AllowedEmailServices service;
    char *full_email;
};

struct PhoneNumberDetails {
    int number_of_bytes;
};

struct Details fill_details(void);

char *fill_phone_number(struct Details *created_struct_parameter);

char *fill_email_address(void); // Matches parameterless definition

int email_menu(void);

char *get_domain_string(enum AllowedEmailServices service);

char *get_username(struct EmailDetails *username_parameter);

char *get_domain(struct EmailDetails *email_parameter);

#endif