/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:29:52 by alejaro2          #+#    #+#             */
/*   Updated: 2024/10/18 18:41:13 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <sys/stat.h>

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
		write(fd, (s++), 1);
	write(fd, "\n", 1);
}

// int	main(void)
// {
// 	char p[] = "holartf";
// 	int fd = open("prueba", O_CREAT | O_WRONLY, 0777);
// 	ft_putendl_fd(p, fd);
// }