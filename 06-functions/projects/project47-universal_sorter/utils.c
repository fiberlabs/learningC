int compare_asc(const void *a, const void *b)
{                          // the mem add of para a and para b
    int *int_a = (int *)a; // tell the compiler to treat this mem add as a int when interpreting
    int *int_b = (int *)b;


    return (*int_a - *int_b);
}

int compare_desc(const void *a, const void *b)
{
    int *int_a = (int *)a;
    int *int_b = (int *)b;

    return (*int_b - *int_a);
}