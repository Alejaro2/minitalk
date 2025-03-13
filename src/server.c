/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:59:49 by alejaro2          #+#    #+#             */
/*   Updated: 2025/03/13 15:21:53 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	resize_buffer(char **buffer, int *size, int i)
{
	char	*temp;
	int		j;

	*size *= 2;
	temp = (char *)malloc(*size * sizeof(char));
	if (!temp)
		exit(1);
	j = 0;
	while (j < i)
	{
		temp[j] = (*buffer)[j];
		j++;
	}
	temp[i] = 0;
	free(*buffer);
	*buffer = temp;
}

static void	init_buffer(char **buffer, int *size)
{
	*size = 1024;
	*buffer = (char *)malloc(*size * sizeof(char));
	if (!*buffer)
		exit(1);
	(*buffer)[0] = 0;
}

static void	process_char(char **buffer, int *size, unsigned char c)
{
	static int	i = 0;

	if (i >= *size - 1)
		resize_buffer(buffer, size, i);
	(*buffer)[i++] = c;
	if (c == '\0')
	{
		ft_printf("%s\n", *buffer);
		free(*buffer);
		*buffer = NULL;
		i = 0;
		*size = 0;
	}
}

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static unsigned char	c = 0;
	static int				bit_count = 0;
	static char				*buffer = NULL;
	static int				size = 0;

	(void)context;
	if (!buffer)
		init_buffer(&buffer, &size);
	if (sig == SIGUSR1)
		c = c << 1; 
	else if (sig == SIGUSR2)
		c = (c << 1) | 1;
	bit_count++;
	if (bit_count == 8)
	{
		process_char(&buffer, &size, c);
		c = 0;
		bit_count = 0;
	}
	if (info->si_pid > 0)
		kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
