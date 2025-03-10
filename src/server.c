/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:59:49 by alejaro2          #+#    #+#             */
/*   Updated: 2025/03/10 10:38:35 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	signal_handler(int sig)
{
	static unsigned char	c;
	static int				bit_count;

	c = 0;
	bit_count = 0;
	
	ft_printf("señal recibida: %d\n", sig);
	if (sig == SIGUSR1)
		c = c << 1;
	else if (sig == SIGUSR2)
		c = (c << 1) | 1;
	bit_count++;
	ft_printf("bit_count: %d, c: %d\n", bit_count, c);
	if (bit_count == 8)
	{
		if(c != '\0')
			ft_printf("%c", c);
		else
			ft_printf("\n");
		c = 0;
		bit_count = 0;
	}
}

int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}