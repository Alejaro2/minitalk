/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:59:49 by alejaro2          #+#    #+#             */
/*   Updated: 2025/03/07 19:00:36 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "../libft/printf/ft_printf.h"

static void signal_handler(int sig)
{
	static unsigned char c = 0;
	static int bit_count = 0;
	if(sig == SIGUSR1)
		c = c << 1;
	else if (sig == SIGUSR2)
		c = (c << 1) | 1;
	bit_count++;
	if(bit_count == 8)
	{
		if(c == '\0')
			ft_printf("Mensaje completado");
	}
		
}

int main(void)
{
	ft_printf("Server PID: %d\n",  getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while(1)
		pause();
	return(0);
}