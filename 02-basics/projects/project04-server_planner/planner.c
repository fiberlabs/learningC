#include <stdio.h>

int main() 
{
    int no_of_servers;
    int cpu_cores;
    int ram_per_server;
    double monthly_cost_per_server;

    printf("how many servers are there?: ");
    scanf("%d", &no_of_servers);
    printf("how many cpu cores per server are there?: ");
    scanf("%d", &cpu_cores);
    printf("how much RAM (in GBs) in each server?: ");
    scanf("%d", &ram_per_server);
    printf("what is the monthly cost per server (in $USD)?: ");
    scanf("%lf", &monthly_cost_per_server);

    int total_cores = no_of_servers * cpu_cores;
    int total_RAM_GB = no_of_servers * ram_per_server;
    long long int total_RAM_bytes = (long long int)total_RAM_GB * 1073741824;
    double total_cost = (double)no_of_servers * monthly_cost_per_server;

    printf("QUOTE:\n");
    printf("Total Cores:         \t%d\n", total_cores);
    printf("Total RAM (GBs):     \t%d\n", total_RAM_GB);
    printf("Total RAM (in bytes):\t%lld\n", total_RAM_bytes);
    printf("Cost/Month:          \t%.2lf\n", total_cost);

    return 0;
}

/*

*/