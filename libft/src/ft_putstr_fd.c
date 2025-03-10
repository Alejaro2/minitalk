/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:14:39 by alejaro2          #+#    #+#             */
/*   Updated: 2024/10/18 19:12:12 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, (s++), 1);
}
/*int main()
{
	char p[] = "holartf";
	int fd = open("prueba", O_CREAT | O_WRONLY, 0777);
	ft_putstr_fd(p, fd);
}*/
