#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int hasUpper = 0;
    int hasLower = 0;
    int hasDigit = 0;
    int hasSpecial = 0;
    int score = 0;

    //take user input
    printf("Enter a password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';
    

    //analyze the password
    for (int i = 0; password[i] != '\0'; i++) {
        if (isupper(password[i])) hasUpper = 1;
        if (islower(password[i])) hasLower = 1;
        if (isdigit(password[i])) hasDigit = 1;
        if (ispunct(password[i])) hasSpecial = 1;
    }

    //once the character analysis is done, now we should check for the length
    if (strlen(password) >= 8) score++;
    if (hasUpper) score++;
    if (hasLower) score++;
    if (hasDigit) score++;
    if (hasSpecial) score++;

    //print the strength
    printf("Password strength: ");
    if (score <= 2) {
        printf("Weak\n");
    } else if (score <= 4) {
        printf("Moderate\n");
    } else {
        printf("Strong\n");
    }

    return 0;
}