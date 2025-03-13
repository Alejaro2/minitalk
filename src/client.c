/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:08:20 by alejaro2          #+#    #+#             */
/*   Updated: 2025/03/13 11:01:32 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t	g_bit_confirmed = 0;

static void	ack_handler(int sig)
{
	(void)sig;
	g_bit_confirmed = 1;
}

static void	send_char(int pid, unsigned char c)
{
	int		bit;
	long	time;

	bit = 8;
	while (bit--)
	{
		g_bit_confirmed = 0;
		if ((c >> bit) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		time = 0;
		while (!g_bit_confirmed && time < TIMEOUT)
		{
			usleep(10);
			time++;
		}
		if (time == TIMEOUT)
		{
			ft_printf("Error: No response from server");
			exit(1);
		}
	}
}

static void	send_message(int pid, char *message)
{
	int	i;

	i = 0;
	while (message[i])
	{
		send_char(pid, message[i]);
		i++;
	}
	send_char(pid, '\0');
}

static int	is_validate_pid(char *pid_str)
{
	int	i;

	i = 0;
	while (pid_str[i])
	{
		if (!ft_isdigit(pid_str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					pid;

	if (argc != 3 || !ft_strlen(argv[2]) || !is_validate_pid(argv[1]))
	{
		ft_putstr_fd("ERROR: Invalid arguments!\n", 2);
		ft_putstr_fd("USAGE: ./client <PID_servidor> \"Mensaje\"\n", 2);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	sa.sa_handler = ack_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	ft_printf("Sending message to (PID: %d)...\n", pid);
	send_message(pid, argv[2]);
	ft_printf("Message sent successfully.\n");
	return (0);
}
