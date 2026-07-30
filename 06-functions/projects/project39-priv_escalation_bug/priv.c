#include <stdio.h>

void grant_adminFAKE(int isAdminPara) //pass by val
{
    isAdminPara = 1;
}

void grant_adminWORK(int *isAdminPara) //pass by ref
{
    *isAdminPara = 1;
}

int main()
{
    int isAdmin = 0;

    if (isAdmin)
    {
        printf("access granted\n");
    }
    else
    {
        printf("you dont have admin priv\n");
    }

    grant_adminFAKE(isAdmin);

    if (isAdmin)
    {
        printf("access granted\n");
    }
    else
    {
        printf("you dont have admin priv\n");
    }

    grant_adminWORK(&isAdmin);

    if (isAdmin)
    {
        printf("access granted\n");
    }
    else
    {
        printf("you dont have admin priv\n");
    }

    return 0;
}
