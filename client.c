#include "minitalk.h"

int main(int argc, char **argv)
{
    pid_t server_pid;

    if (argc != 3)
        return (1);

    server_pid = atoi(argv[1]);
    send_string(server_pid, argv[2]);

    return (0);
}



void send_char(pid_t server_pid, unsigned char c)
{
    int i;
    int bit;

    i = 7;
    while (i >= 0)
    {
        bit = (c >> i) & 1;

        if (bit == 1)
            kill(server_pid, SIGUSR1);
        else
            kill(server_pid, SIGUSR2);

        usleep(200);
        i--;
    }
}

void send_string(pid_t server_pid, char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        send_char(server_pid, str[i]);
        i++;
    }
    send_char(server_pid, '\0');
}

