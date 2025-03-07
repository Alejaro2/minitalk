/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:59:49 by alejaro2          #+#    #+#             */
/*   Updated: 2025/03/07 13:28:38 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "../libft/printf/ft_printf.h"

static void signal_handler(int sig)
{
	if(sig == SIGUSR1)
		ft_printf("Recibi SIGUSR1\n");
	else if (sig == SIGUSR2)
		ft_printf("Recibi SIGUSR2\n");
}

int main(void)
{
	__pid_t pid = getpid();
	ft_printf("Server PID: %d\n",  pid);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while(1)
		pause();
	return(0);
}