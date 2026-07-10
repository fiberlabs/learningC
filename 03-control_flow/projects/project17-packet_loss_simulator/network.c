#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL)); // seed value

    int packet_success = 0; // bool (1 is success, 0 is failure)
    int retry_attempt = 5;  // starts from 5 and will go down to 0

    for (int packet_no = 1; packet_no <= 10; packet_no++)
    {
        // for each loop do this
        while (retry_attempt > 0)
        {
            printf("\nsending packet number %d\n", packet_no);
            packet_success = rand() % 2; // check if it fails

            // if it fails, do this
            if (!packet_success)
            {
                printf("packet %d failed to send, attempting to resend the packet (%d / 5)\n", packet_no, retry_attempt);
                retry_attempt--;
                continue; // will go back to the start of the while loop
            }
            else //if it worked
            {
                retry_attempt = 5; //reset the retry attempt for future packets
                printf("packet %d sent!\n", packet_no);
                break; //exit the while loop so it can go to the next packet number
            }
        }

        if (retry_attempt <= 0) //if retry attempts have run out...
        {
            printf("connection error\n"); //end the program
            return 1;
        }
    }

    //it works

    return 0;
}