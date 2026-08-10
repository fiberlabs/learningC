#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

char *fill_phone_number(struct Details *created_struct_parameter)
{
    int number_of_bytes = 0;
    int index = 0;

    // phone numbers are usually 13 digits, so ill use that.
    created_struct_parameter->phone_number = malloc((13 + 1) * sizeof(char)); //+1 for the nullbyte
    if (created_struct_parameter->phone_number == NULL) {
        printf("error during malloc for phone number, exiting\n");
        return NULL;
    }

    // get user input
    printf("enter the 13 digit phone number: ");
    int phone_input;
    while ((phone_input = getchar()) != '\n' && phone_input != EOF)
    {
        //bounds check
        if (number_of_bytes < 14) {
            number_of_bytes++;
            created_struct_parameter->phone_number[index] = phone_input;
            index++;
        } 
        else {
            printf("exceeded 13 digits, exiting\n");
            break;
        }
    }

    created_struct_parameter->phone_number[number_of_bytes] = '\0';

    printf("\nmemory address: %p\nvalue: %s\n", (void *)created_struct_parameter->phone_number, created_struct_parameter->phone_number); //for debugging
    return created_struct_parameter->phone_number;
}

struct Details fill_details()
{
    struct Details contact_details;

    contact_details.phone_number = fill_phone_number(&contact_details);

    return contact_details;
}

//temp to actually run the program
int main() {
    fill_details();
    return 0;
}