#ifndef MINITALK_H
#define MINITALK_H


#include<unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <stdio.h>

void send_char(pid_t server_pid, unsigned char c);
void send_string(pid_t server_pid, char *str);


#endif