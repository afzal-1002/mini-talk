#include "minitalk.h"

void handler(int sig)
{
    static int bit = 0;
    static unsigned char c = 0;

    if (sig == SIGUSR1)
        c |= (1 << (7 - bit));

    bit++;

    if (bit == 8)
    {
        write(1, &c, 1);
        bit = 0;
        c = 0;
    }
}

void ft_putnbr(int num)
{
    char c;

    if (num == -2147483648)
    {
        write(1, "-2147483648", 11);
        return;
    }
    if (num < 0)
    {
        write(1, "-", 1);
        num = -num;
    }
    if (num >= 10)
        ft_putnbr(num / 10);
    c = (num % 10) + '0';
    write(1, &c, 1);
}

int main(void)
{
    // pid_t pid;
    struct sigaction sa;
    // pid =  getpid();
    write(1, "Server PID: ", 12);
    ft_putnbr(getpid());
    // printf("%d ", PID);
    write(1, "\n", 1);

    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;


    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);

    while (1)
        pause();
}
