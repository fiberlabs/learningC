#include <stdio.h>
#include <string.h>

enum PacketType {
    INTEGER_PAYLOAD,
    FLOAT_PAYLOAD,
    CHARACTER_PAYLOAD
};

union PacketData {
    int int_data;
    float float_data;
    char text_data[10];

};

struct Packet{
    int id;
    enum PacketType packet_type;
    union PacketData packet_data;
};

#define CAPACITY 3

int main()
{
    struct Packet packets[CAPACITY];
    int count = 0;

    //intializing them
    packets[0].id = 100;
    packets[0].packet_type = INTEGER_PAYLOAD;
    packets[0].packet_data.int_data = 404;
    count++;

    packets[1].id = 101;
    packets[1].packet_type = FLOAT_PAYLOAD;
    packets[1].packet_data.float_data = 3.14;
    count++;

    packets[2].id = 102;
    packets[2].packet_type = CHARACTER_PAYLOAD;
    strcpy(packets[2].packet_data.text_data,"OK!");
    count++;

    for (int i = 0; i < count; i++) {
        switch (packets[i].packet_type)
        {
        case INTEGER_PAYLOAD:
            printf("ID: %d\n", packets[i].id);
            printf("Data: %d\n", packets[i].packet_data.int_data);
            break;

        case FLOAT_PAYLOAD:
            printf("ID: %d\n", packets[i].id);
            printf("Data: %lf\n", packets[i].packet_data.float_data);
            break;

        case CHARACTER_PAYLOAD:
            printf("ID: %d\n", packets[i].id);
            printf("Data: %s\n", packets[i].packet_data.text_data);
            break;
        
        default:
            break;
        }
    }

    printf("no more packets to read\n");

    return 0;
}