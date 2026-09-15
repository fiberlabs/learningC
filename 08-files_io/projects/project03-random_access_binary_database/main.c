// main.c
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

int main() {
    int user_input = print_menu();

    switch (user_input)
    {
    case 1:
        //ADD RECORD LOGIC
        char *name_para = get_name();
        int age_para = get_age();
        int salary_para = get_salary();

        add_record(name_para, age_para, salary_para);

        free(name_para);
        name_para = NULL;

        break;

    case 2:
        //VIEW RECORD LOGIC
        get_requested_index(list_indexes());
        break;

    case 3:
        //LIST ALL LOGIC
        list_all();
        break;

    case 4:
        //QUIT PROGRAM LOGIC
        exit(1);
        break;

    default:
        break;
    }

    return 0;
}