#include <stdio.h>

void hex_dump(void *ptr, size_t size) {

    unsigned char *bytes = (unsigned char *)ptr;

    for (size_t i = 0; i < size; i++) {
        printf("%02X ", bytes[i]);
    }

    printf("\n");
}

int main() {

    int x = 255;
    hex_dump(&x, sizeof(x));

    return 0;
}