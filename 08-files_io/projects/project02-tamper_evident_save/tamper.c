#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Profile
{
    char name[64];
    int level;
    int health;
    unsigned int checksum;
};

unsigned int calculate_fake_checksum(struct Profile *p)
{ // larp checksum calculator
    unsigned int sum = 0;

    for (int i = 0; p->name[i] != '\0'; i++)
    {
        sum += p->name[i];
    }

    sum ^= p->level;
    sum ^= p->health;

    return sum;
}

int main()
{
    struct Profile p1;

    strcpy(p1.name, "Master Chief");
    p1.level = 53;
    p1.health = 100;
    p1.checksum = 0;

    p1.checksum = calculate_fake_checksum(&p1);

    FILE *fp = fopen("data.dat", "wb");
    if (fp == NULL)
    {
        perror("fopen() returned NULL");
        exit(1);
    }

    fwrite(&p1, sizeof(struct Profile), 1, fp);

    if (fclose(fp) != 0)
    {
        perror("fclose() failed");
        exit(1);
    }

    fp = NULL;

    printf("stored data\n\n");

    fp = fopen("data.dat", "rb");
    if (fp == NULL)
    {
        perror("fopen() returned NULL");
        exit(1);
    }

    struct Profile temp;
    fread(&temp, sizeof(struct Profile), 1, fp);

    if (fclose(fp) != 0)
    {
        perror("fclose() failed");
        exit(1);
    }

    fp = NULL;

    printf("read data\n\n");

    unsigned int recomputed = calculate_fake_checksum(&temp);
    if (recomputed != temp.checksum)
    {
        printf("tampered!\n");
    }
    else
    {
        printf("not tampered!\n");
    }

    return 0;
};