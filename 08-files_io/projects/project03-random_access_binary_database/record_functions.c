// record_functions.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

// ADD RECORD FUNCTIONS

char *get_name()
{
    int bytes_used = 0;
    int byte_index = 0;

    int capacity = 8;
    char *name_buffer = malloc(capacity * sizeof(char));
    if (name_buffer == NULL)
    {
        printf("error: malloc for name_buffer returned NULL\n");
        return NULL;
    }

    printf("enter the employee's name: ");
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        bytes_used++;

        while (1)
        {
            if (bytes_used > capacity - 1)
            {

                char *temp_buffer = realloc(name_buffer, (capacity * 2) * sizeof(char));
                if (temp_buffer == NULL)
                {
                    printf("error: malloc for name_buffer returned NULL\n");
                    free(name_buffer);
                    return NULL;
                }

                capacity *= 2;
                name_buffer = temp_buffer;
            }
            else
            {
                break;
            }
        }

        name_buffer[byte_index] = c;
        byte_index++;
    }

    name_buffer[bytes_used] = '\0';

    return name_buffer;
}

int get_age()
{
    int x = 0;

    while (x < 18)
    {
        printf("enter the employee's age: ");
        if (scanf("%d", &x) == 1)
        {
            // clear input buffer
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
        }

        if (x < 18)
        {
            printf("must be at least 18 years old\ntry again\n");
        }
    }

    return x;
}

int get_salary()
{
    int x = 0;

    while (x < 1)
    {
        printf("enter the employee's salary: ");
        if (scanf("%d", &x) == 1)
        {
            // clear input buffer
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
        }

        if (x < 1)
        {
            printf("salary has to be greater than 1\ntry again\n");
        }
    }

    return x;
}

void add_record(char *name_parameter, int age_parameter, int salary_parameter)
{

    // before we do anything else
    if (name_parameter == NULL)
    {
        perror("name_parameter is NULL, get_name() probably failed somewhere");
        exit(1);
    }

    struct Record new_record = {0};

    strcpy(new_record.name, name_parameter);
    new_record.age = age_parameter;
    new_record.salary = salary_parameter;

    FILE *fp = NULL;

    fp = fopen("records.dat", "ab");
    if (fp == NULL)
    {
        perror("fopen() for add_record() returned NULL");
        exit(1);
    }

    fwrite(&new_record, sizeof(struct Record), 1, fp);

    if (fclose(fp) != 0)
    {
        perror("fclose() for add_record() failed");
        exit(1);
    }

    free(name_parameter); // we dont need this allocated memory anymore once the record is added
    name_parameter = NULL;
    fp = NULL;

    printf("Added record for %s successfully\n", new_record.name);
}