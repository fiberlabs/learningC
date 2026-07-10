#include <stdio.h>

int main() {
	int age;
	printf("how old are you?: ");
	scanf("%d", &age);

	printf("1 means you can vote, 0 means you can't:\t%d\n", age >=18);
	return 0;
}
