/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 20:13:20 by mafzal            #+#    #+#             */
/*   Updated: 2025/12/18 20:40:09 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

void	send_char(pid_t server_pid, unsigned char c);
void	send_string(pid_t server_pid, char *str);
int		ft_atoi(const char *str);
void	handler(int sig);
void	ft_putnbr(int num);

#endif
