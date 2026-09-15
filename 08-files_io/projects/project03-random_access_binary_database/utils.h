// utils.h

struct Record {
    char name[64];
    int age;
    int salary;
};

//menu functions
int print_menu();
int get_menu_input();

//add record functions
char *get_name();
int get_age();
int get_salary();

void add_record(char *name_parameter, int age_parameter, int salary_parameter);