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

    strncpy(new_record.name, name_parameter, sizeof(new_record.name) - 1);
    new_record.name[sizeof(new_record.name) - 1] = '\0';
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
    
    fp = NULL;

    printf("Added record for %s successfully\n", new_record.name);
}

// LIST ALL LOGIC
void list_all() {
    struct Record recieve_record = {0};

    FILE *fp = NULL;
    fp = fopen("records.dat", "rb");
    if (fp == NULL) {
        perror("fopen() for list_all() returned NULL");
        exit(1);
    }

    int index = 0;

    while (fread(&recieve_record, sizeof(struct Record), 1, fp) == 1) 
    {
        printf("\n");
        printf("Index: %d\nName: %s\nAge: %d\nSalary: %d\n", index + 1, recieve_record.name, recieve_record.age, recieve_record.salary);
        index++;
    }

    if (fclose(fp) != 0)
    {
        perror("fclose() for list_all() failed");
        exit(1);
    }

    fp = NULL;
}

// VIEW RECORD LOGIC
void get_requested_index(int index_to_fetch) { //list_indexes() is in menu_functions.c
    FILE *fp = NULL;

    fp = fopen("records.dat", "rb");
    if (fp == NULL) {
        perror("fopen() for get_requested_index() failed");
        exit(1);
    }

    long offset = (index_to_fetch - 1) * sizeof(struct Record);
    if (fseek(fp, offset, SEEK_SET) != 0) {
        perror("fseek() in get_requested_index() failed\n");
        fclose(fp);
        exit(1);
    }

    struct Record record_index_to_get = {0};
    fread(&record_index_to_get, sizeof(struct Record), 1, fp);
    
    printf("\n");
    printf("Name: %s\nAge: %d\nSalary: %d\n", record_index_to_get.name, record_index_to_get.age, record_index_to_get.salary);

    if (fclose(fp) != 0) {
        perror("fclose() for get_requested_index() failed");
        exit(1);
    }
}