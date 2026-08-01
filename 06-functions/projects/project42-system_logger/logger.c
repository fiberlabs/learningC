#include <stdio.h>
#include <stdarg.h>

enum Severity
{
    INFO,
    WARNING,
    ERROR
};

void print_log(enum Severity severity, ...)
{
    const char *levels[] =
    {
        "INFO",
        "WARNING",
        "ERROR"
    };

    va_list args;

    va_start(args, severity);

    const char *log = va_arg(args, const char *);

    printf("[%s] %s", levels[severity], log);

    va_end(args);
}

int main(void)
{
    print_log(0, "Successful Log In.\n");
    print_log(1, "Disk usage at %d%%.\n", 85);
    print_log(2, "Failed to open file 'data.bin'.\n");
    return 0;
}

//i will come back to finish this properly in a bit, idk why i cant get my head around the
//concept right now